/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   class definition for the VP8 output module

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __OUTPUT_P_VP8_H
#define __OUTPUT_P_VP8_H

#include "common/common_pch.h"

#include "merge/pr_generic.h"

class vp8_video_packetizer_c: public generic_packetizer_c {
public:
  vp8_video_packetizer_c(generic_reader_c *p_reader, track_info_c &p_ti);

  virtual int process(packet_cptr packet);
  virtual void set_headers();

  virtual const std::string get_format_name(bool translate = true) {
    return translate ? Y("VP8") : "VP8";
  }

  virtual connection_result_e can_connect_to(generic_packetizer_c *src, std::string &error_message);
  virtual bool is_compatible_with(output_compatibility_e compatibility);
};

#endif // __OUTPUT_P_VP8_H
