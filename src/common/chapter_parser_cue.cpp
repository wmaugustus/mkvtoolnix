/*
 * mkvmerge -- utility for splicing together matroska files
 * from component media subtypes
 *
 * Distributed under the GPL
 * see the file COPYING for details
 * or visit http://www.gnu.org/copyleft/gpl.html
 *
 * $Id$
 *
 * chapter parser for CUE sheets
 *
 * Written by Moritz Bunkus <moritz@bunkus.org>.
 * Patches by Nicolas Le Guen <nleguen@pepper-prod.com> and
 * Vegard Pettersen <vegard_p@broadpark.no>
 */

#include <ctype.h>
#include <stdarg.h>

#include <string>

#include <matroska/KaxChapters.h>
#include <matroska/KaxTag.h>
#include <matroska/KaxTags.h>

#include "chapters.h"
#include "commonebml.h"
#include "error.h"
#include "matroska.h"

using namespace std;
using namespace libmatroska;

// PERFORMER "Blackmore's Night"
// TITLE "Fires At Midnight"
// FILE "Range.wav" WAVE
//   TRACK 01 AUDIO
//     TITLE "Written In The Stars"
//     PERFORMER "Blackmore's Night"
//     INDEX 01 00:00:00
//   TRACK 02 AUDIO
//     TITLE "The Times They Are A Changin'"
//     PERFORMER "Blackmore's Night"
//     INDEX 00 04:46:62
//     INDEX 01 04:49:64

bool
probe_cue_chapters(mm_text_io_c *in) {
  string s;

  in->setFilePointer(0);
  if (!in->getline2(s))
    return false;
  if (starts_with_case(s, "performer ") || starts_with_case(s, "title ") ||
      starts_with_case(s, "file ") || starts_with_case(s, "catalog ") ||
      starts_with_case(s, "rem "))
    return true;
  return false;
}

string cue_to_chapter_name_format;

static void
cue_entries_to_chapter_name(string &performer,
                            string &title,
                            string &global_performer,
                            string &global_title,
                            string &name,
                            int num) {
  const char *this_char, *next_char;

  name = "";
  if (title.length() == 0)
    title = global_title;
  if (performer.length() == 0)
    performer = global_performer;

  if (cue_to_chapter_name_format == "")
    this_char = "%p - %t";
  else
    this_char = cue_to_chapter_name_format.c_str();
  next_char = this_char + 1;
  while (*this_char != 0) {
    if (*this_char == '%') {
      if (*next_char == 'p')
        name += performer;
      else if (*next_char == 't')
        name += title;
      else if (*next_char == 'n')
        name += to_string(num);
      else if (*next_char == 'N') {
        if (num < 10)
          name += '0';
        name += to_string(num);
      } else {
        name += *this_char;
        this_char--;
      }
      this_char++;
    } else
      name += *this_char;
    this_char++;
    next_char = this_char + 1;
  }
}

typedef struct {
  int num;
  int64_t start_of_track;
  vector<int64_t> start_indices;
  bool index00_missing;
  int64_t end;
  int64_t min_tc;
  int64_t max_tc;
  int64_t offset;
  KaxChapters *chapters;
  KaxEditionEntry *edition;
  KaxChapterAtom *atom;
  bool do_convert;
  string global_catalog;
  string global_performer;
  string performer;
  string global_title;
  string title;
  string name;
  string global_date;
  string date;
  string global_genre;
  string genre;
  string global_disc_id;
  string isrc;
  string flags;
  vector<string> global_rem;
  vector<string> global_comment;
  vector<string> comment;
  string language;
  int line_num;
  int cc_utf8;
} cue_parser_args_t;

static UTFstring
cue_str_internal_to_utf(cue_parser_args_t &a,
                        const string &s) {
  if (a.do_convert)
    return cstrutf8_to_UTFstring(to_utf8(a.cc_utf8, s));
  else
    return cstrutf8_to_UTFstring(s);
}

static KaxTagSimple *
create_simple_tag(cue_parser_args_t &a,
                  const string &name,
                  const string &value) {
  KaxTagSimple *simple;

  simple = new KaxTagSimple;
  *static_cast<EbmlUnicodeString *>(&GetChild<KaxTagName>(*simple)) =
    cue_str_internal_to_utf(a, name);
  *static_cast<EbmlUnicodeString *>(&GetChild<KaxTagString>(*simple)) =
    cue_str_internal_to_utf(a, value);

  return simple;
}

#define create_tag1(v1, text) \
  if (v1 != "") \
    tag->PushElement(*create_simple_tag(a, text, v1));
#define create_tag2(v1, v2, text) \
  if (((v1) != "" ? (v1) : (v2)) != "") \
    tag->PushElement(*create_simple_tag(a, text, ((v1) != "" ? (v1) : (v2))));

static void
add_tag_for_cue_entry(cue_parser_args_t &a,
                      KaxTags **tags,
                      uint32_t cuid) {
  KaxTag *tag;
  KaxTagTargets *targets;
  string s;
  int i;

  if (tags == NULL)
    return;

  if (*tags == NULL)
    *tags = new KaxTags;

  tag = new KaxTag;
  targets = &GetChild<KaxTagTargets>(*tag);
  *static_cast<EbmlUInteger *>(&GetChild<KaxTagChapterUID>(*targets)) = cuid;
  *static_cast<EbmlUInteger *>(&GetChild<KaxTagTargetTypeValue>(*targets)) =
    TAG_TARGETTYPE_TRACK;
  *static_cast<EbmlString *>(&GetChild<KaxTagTargetType>(*targets)) = "track";

  create_tag1(a.title, "TITLE");
  tag->PushElement(*create_simple_tag(a, "PART_NUMBER",
                                      mxsprintf("%d", a.num)));
  create_tag2(a.performer, a.global_performer, "ARTIST");
  create_tag2(a.date, a.global_date, "DATE_RELEASED");
  create_tag2(a.genre, a.global_genre, "GENRE");
  create_tag1(a.isrc, "ISRC");
  create_tag1(a.flags, "CDAUDIO_TRACK_FLAGS");
  for (i = 0; i < a.global_comment.size(); i++)
    create_tag1(a.global_comment[i], "COMMENT");
  for (i = 0; i < a.comment.size(); i++)
    create_tag1(a.comment[i], "COMMENT");

  (*tags)->PushElement(*tag);
}

static void
add_tag_for_global_cue_settings(cue_parser_args_t &a,
                                KaxTags **tags) {
  KaxTag *tag;
  KaxTagTargets *targets;
  string s;
  int i;

  if (tags == NULL)
    return;

  if (*tags == NULL)
    *tags = new KaxTags;

  tag = new KaxTag;

  targets = &GetChild<KaxTagTargets>(*tag);
  *static_cast<EbmlUInteger *>(&GetChild<KaxTagTargetTypeValue>(*targets)) =
    TAG_TARGETTYPE_ALBUM;
  *static_cast<EbmlString *>(&GetChild<KaxTagTargetType>(*targets)) = "album";

  create_tag1(a.global_performer, "ARTIST");
  create_tag1(a.global_title, "TITLE");
  create_tag1(a.global_date, "DATE_RELEASED");
  create_tag1(a.global_disc_id, "DISCID");
  create_tag1(a.global_catalog, "CATALOG_NUMBER");
  for (i = 0; i < a.global_rem.size(); i++)
    create_tag1(a.global_rem[i], "COMMENT");

  (*tags)->PushElement(*tag);
}

static void
add_subchapters_for_index_entries(cue_parser_args_t &a) {
  KaxChapterAtom *atom;
  KaxChapterDisplay *display;
  int i, offset;

  if (a.start_indices.empty())
    return;

  if (a.index00_missing)
    offset = 1;
  else
    offset = 0;

  atom = NULL;
  for (i = 0; i < a.start_indices.size(); i++) {
    if (atom == NULL)
      atom = &GetChild<KaxChapterAtom>(*a.atom);
    else
      atom = &GetNextChild<KaxChapterAtom>(*a.atom, *atom);

    *static_cast<EbmlUInteger *>(&GetChild<KaxChapterUID>(*atom)) =
      create_unique_uint32(UNIQUE_CHAPTER_IDS);
    *static_cast<EbmlUInteger *>(&GetChild<KaxChapterTimeStart>(*atom)) =
      a.start_indices[i] - a.offset;

    display = &GetChild<KaxChapterDisplay>(*atom);
    *static_cast<EbmlUnicodeString *>(&GetChild<KaxChapterString>(*display)) =
      cstrutf8_to_UTFstring(mxsprintf("INDEX %02d", i + offset).c_str());
    *static_cast<EbmlString *>(&GetChild<KaxChapterLanguage>(*display)) =
      "eng";

    *static_cast<EbmlUInteger *>(&GetChild<KaxChapterFlagHidden>(*atom)) = 1;
    *static_cast<EbmlUInteger *>(&GetChild<KaxChapterPhysicalEquiv>(*atom)) =
      CHAPTER_PHYSEQUIV_INDEX;
  }
}

static void
add_elements_for_cue_entry(cue_parser_args_t &a,
                           KaxTags **tags) {
  KaxChapterDisplay *display;
  UTFstring wchar_string;
  uint32_t cuid;

  if (a.start_indices.empty())
    mxerror("Cue sheet parser: No INDEX entry found for the previous "
            "TRACK entry (current line: %d)\n", a.line_num);
  if (!((a.start_indices[0] >= a.min_tc) &&
        ((a.start_indices[0] <= a.max_tc) || (a.max_tc == -1))))
    return;

  if (a.edition == NULL) {
    a.edition = &GetChild<KaxEditionEntry>(*a.chapters);
    *static_cast<EbmlUInteger *>(&GetChild<KaxEditionUID>(*a.edition)) =
      create_unique_uint32(UNIQUE_EDITION_IDS);
  }
  if (a.atom == NULL)
    a.atom = &GetChild<KaxChapterAtom>(*a.edition);
  else
    a.atom = &GetNextChild<KaxChapterAtom>(*a.edition, *a.atom);
  *static_cast<EbmlUInteger *>(&GetChild<KaxChapterPhysicalEquiv>(*a.atom)) =
    CHAPTER_PHYSEQUIV_TRACK;

  cuid = create_unique_uint32(UNIQUE_CHAPTER_IDS);
  *static_cast<EbmlUInteger *>(&GetChild<KaxChapterUID>(*a.atom)) = cuid;

  *static_cast<EbmlUInteger *>(&GetChild<KaxChapterTimeStart>(*a.atom)) =
    a.start_of_track - a.offset;

  display = &GetChild<KaxChapterDisplay>(*a.atom);

  cue_entries_to_chapter_name(a.performer, a.title, a.global_performer,
                              a.global_title, a.name, a.num);
  *static_cast<EbmlUnicodeString *> (&GetChild<KaxChapterString>(*display)) =
    cue_str_internal_to_utf(a, a.name);

  *static_cast<EbmlString *>(&GetChild<KaxChapterLanguage>(*display)) =
    a.language;

  add_subchapters_for_index_entries(a);

  add_tag_for_cue_entry(a, tags, cuid);
}

static string
get_quoted(string src,
           int offset) {
  src.erase(0, offset);
  strip(src);
  if ((src.length() > 0) && (src[0] == '"'))
    src.erase(0, 1);
  if ((src.length() > 0) && (src[src.length() - 1] == '"'))
    src.erase(src.length() - 1);

  return src;
}

static string
erase_colon(string &s,
            int skip) {
  int i;

  i = skip + 1;
  while ((i < s.length()) && (s[i] == ' '))
    i++;
  while ((i < s.length()) && (isalpha(s[i])))
    i++;
  if (i == s.length())
    return s;
  if (s[i] == ':')
    s.erase(i, 1);
  else if (s.substr(i, 2) == " :")
    s.erase(i, 2);
  return s;
}

KaxChapters *
parse_cue_chapters(mm_text_io_c *in,
                   int64_t min_tc,
                   int64_t max_tc,
                   int64_t offset,
                   const string &language,
                   const string &charset,
                   bool exception_on_error,
                   KaxTags **tags) {
  cue_parser_args_t a;
  string line;
  
  in->setFilePointer(0);
  a.chapters = new KaxChapters;

  if (in->get_byte_order() == BO_NONE) {
    a.do_convert = true;
    a.cc_utf8 = utf8_init(charset.c_str());

  } else {
    a.do_convert = false;
    a.cc_utf8 = 0;
  }

  if (language == "")
    a.language = "eng";
  else
    a.language = language;

  a.min_tc = min_tc;
  a.max_tc = max_tc;
  a.offset = offset;

  a.atom = NULL;
  a.edition = NULL;
  a.num = 0;
  a.line_num = 0;
  a.start_of_track = -1;
  try {
    while (in->getline2(line)) {
      a.line_num++;
      strip(line);
      if ((line.length() == 0) || starts_with_case(line, "file "))
        continue;

      if (starts_with_case(line, "performer ")) {
        if (a.num == 0)
          a.global_performer = get_quoted(line, 10);
        else
          a.performer = get_quoted(line, 10);

      } else if (starts_with_case(line, "catalog "))
        a.global_catalog = get_quoted(line, 8);

      else if (starts_with_case(line, "title ")) {
        if (a.num == 0)
          a.global_title = get_quoted(line, 6);
        else
          a.title = get_quoted(line, 6);

      } else if (starts_with_case(line, "index ")) {
        int index, min, sec, frames;
        bool index_ok;

        line.erase(0, 6);
        strip(line);
        if (sscanf(line.c_str(), "%d %d:%d:%d", &index, &min, &sec, &frames) <
            4)
          mxerror("Cue sheet parser: Invalid INDEX entry in line %d.\n",
                  a.line_num);

        index_ok = false;
        if ((index >= 0) && (index <= 99)) {
          if ((a.start_indices.size() == 0) && (index == 1))
            a.index00_missing = true;
          if ((a.start_indices.size() == index) ||
              ((a.start_indices.size() == (index - 1)) && a.index00_missing)) {
            int64_t timestamp = min * 60 * 1000000000ll + sec * 1000000000ll +
              frames * 1000000000ll / 75;
            a.start_indices.push_back(timestamp);
            if ((index == 1) || (index == 0)) 
              a.start_of_track = timestamp;
            index_ok = true;
          }
        }

        if (!index_ok)
          mxerror("Cue sheet parser: Invalid INDEX number (got %d, "
                  "expected %d) in line %d,\n",
                  index, a.start_indices.size(), a.line_num); 

      } else if (starts_with_case(line, "track ")) {
        if ((line.length() < 5) ||
            strcasecmp(&line[line.length() - 5], "audio"))
          continue;

        if (a.num >= 1)
          add_elements_for_cue_entry(a, tags);
        else
          add_tag_for_global_cue_settings(a, tags);

        a.num++;
        a.start_of_track = -1;
        a.start_indices.clear();
        a.index00_missing = false;
        a.performer = "";
        a.title = "";
        a.isrc = "";
        a.comment.clear();
        a.date = "";
        a.genre = "";
        a.flags = "";

      } else if (starts_with_case(line, "isrc "))
        a.isrc = get_quoted(line, 5);

      else if (starts_with_case(line, "flags "))
        a.flags = get_quoted(line, 6);

      else if (starts_with_case(line, "rem ")) {
        erase_colon(line, 4);
        if (starts_with_case(line, "rem date ") ||
            starts_with_case(line, "rem year ")) {
          if (a.num == 0)
            a.global_date = get_quoted(line, 9);
          else
            a.date = get_quoted(line, 9);

        } else if (starts_with_case(line, "rem genre ")) {
          if (a.num == 0)
            a.global_genre = get_quoted(line, 10);
          else
            a.genre = get_quoted(line, 10);

        } else if (starts_with_case(line, "rem discid "))
          a.global_disc_id = get_quoted(line, 11);

        else if (starts_with_case(line, "rem comment ")) {
          if (a.num == 0)
            a.global_comment.push_back(get_quoted(line, 12));
          else
            a.comment.push_back(get_quoted(line, 12));

        } else {
          if (a.num == 0)
            a.global_rem.push_back(get_quoted(line, 4));
          else
            a.comment.push_back(get_quoted(line, 4));
        }
      }
    }

    if (a.num >= 1)
      add_elements_for_cue_entry(a, tags);

  } catch(error_c e) {
    delete in;
    delete a.chapters;
    throw error_c(e);
  }

  delete in;

  if (a.num == 0) {
    delete a.chapters;
    return NULL;
  }

  return a.chapters;
}
