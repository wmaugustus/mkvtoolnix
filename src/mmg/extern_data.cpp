/*
  mkvmerge GUI -- utility for splicing together matroska files
      from component media subtypes

  extern_data.cpp

  Written by Moritz Bunkus <moritz@bunkus.org>
  Parts of this code were written by Florian Wager <root@sirelvis.de>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file
    \version $Id$
    \brief Data for ComboBoxes
    \author Moritz Bunkus <moritz@bunkus.org>
*/

#include "os.h"
#include "extern_data.h"

#define NULL 0

#ifdef SYS_UNIX
const char *sub_charsets[] = {
  "437",
  "500",
  "500V1",
  "850",
  "851",
  "852",
  "855",
  "856",
  "857",
  "860",
  "861",
  "862",
  "863",
  "864",
  "865",
  "866",
  "869",
  "874",
  "904",
  "1026",
  "1046",
  "1047",
  "8859_1",
  "8859_2",
  "8859_3",
  "8859_4",
  "8859_5",
  "8859_6",
  "8859_7",
  "8859_8",
  "8859_9",
  "10646-1:1993",
  "10646-1:1993UCS4",
  "ANSI_X3.4-1968",
  "ANSI_X3.4-1986",
  "ANSI_X3.4",
  "ANSI_X3.110-1983",
  "ANSI_X3.110",
  "ARABIC",
  "ARABIC7",
  "ARMSCII-8",
  "ASCII",
  "ASMO-708",
  "ASMO_449",
  "BALTIC",
  "BIG-5",
  "BIG-FIVE",
  "BIG5-HKSCS",
  "BIG5",
  "BIG5HKSCS",
  "BIGFIVE",
  "BS_4730",
  "CA",
  "CN-BIG5",
  "CN-GB",
  "CN",
  "CP-AR",
  "CP-GR",
  "CP-HU",
  "CP037",
  "CP038",
  "CP273",
  "CP274",
  "CP275",
  "CP278",
  "CP280",
  "CP281",
  "CP282",
  "CP284",
  "CP285",
  "CP290",
  "CP297",
  "CP367",
  "CP420",
  "CP423",
  "CP424",
  "CP437",
  "CP500",
  "CP737",
  "CP775",
  "CP813",
  "CP819",
  "CP850",
  "CP851",
  "CP852",
  "CP855",
  "CP856",
  "CP857",
  "CP860",
  "CP861",
  "CP862",
  "CP863",
  "CP864",
  "CP865",
  "CP866",
  "CP868",
  "CP869",
  "CP870",
  "CP871",
  "CP874",
  "CP875",
  "CP880",
  "CP891",
  "CP903",
  "CP904",
  "CP905",
  "CP912",
  "CP915",
  "CP916",
  "CP918",
  "CP920",
  "CP922",
  "CP930",
  "CP932",
  "CP933",
  "CP935",
  "CP936",
  "CP937",
  "CP939",
  "CP949",
  "CP950",
  "CP1004",
  "CP1026",
  "CP1046",
  "CP1047",
  "CP1070",
  "CP1079",
  "CP1081",
  "CP1084",
  "CP1089",
  "CP1124",
  "CP1125",
  "CP1129",
  "CP1132",
  "CP1133",
  "CP1160",
  "CP1161",
  "CP1162",
  "CP1163",
  "CP1164",
  "CP1250",
  "CP1251",
  "CP1252",
  "CP1253",
  "CP1254",
  "CP1255",
  "CP1256",
  "CP1257",
  "CP1258",
  "CP1361",
  "CP10007",
  "CPIBM861",
  "CSA7-1",
  "CSA7-2",
  "CSASCII",
  "CSA_T500-1983",
  "CSA_T500",
  "CSA_Z243.4-1985-1",
  "CSA_Z243.4-1985-2",
  "CSA_Z243.419851",
  "CSA_Z243.419852",
  "CSDECMCS",
  "CSEBCDICATDE",
  "CSEBCDICATDEA",
  "CSEBCDICCAFR",
  "CSEBCDICDKNO",
  "CSEBCDICDKNOA",
  "CSEBCDICES",
  "CSEBCDICESA",
  "CSEBCDICESS",
  "CSEBCDICFISE",
  "CSEBCDICFISEA",
  "CSEBCDICFR",
  "CSEBCDICIT",
  "CSEBCDICPT",
  "CSEBCDICUK",
  "CSEBCDICUS",
  "CSEUCKR",
  "CSEUCPKDFMTJAPANESE",
  "CSGB2312",
  "CSHPROMAN8",
  "CSIBM037",
  "CSIBM038",
  "CSIBM273",
  "CSIBM274",
  "CSIBM275",
  "CSIBM277",
  "CSIBM278",
  "CSIBM280",
  "CSIBM281",
  "CSIBM284",
  "CSIBM285",
  "CSIBM290",
  "CSIBM297",
  "CSIBM420",
  "CSIBM423",
  "CSIBM424",
  "CSIBM500",
  "CSIBM851",
  "CSIBM855",
  "CSIBM856",
  "CSIBM857",
  "CSIBM860",
  "CSIBM863",
  "CSIBM864",
  "CSIBM865",
  "CSIBM866",
  "CSIBM868",
  "CSIBM869",
  "CSIBM870",
  "CSIBM871",
  "CSIBM880",
  "CSIBM891",
  "CSIBM903",
  "CSIBM904",
  "CSIBM905",
  "CSIBM918",
  "CSIBM922",
  "CSIBM930",
  "CSIBM932",
  "CSIBM933",
  "CSIBM935",
  "CSIBM937",
  "CSIBM939",
  "CSIBM943",
  "CSIBM1026",
  "CSIBM1124",
  "CSIBM1129",
  "CSIBM1132",
  "CSIBM1133",
  "CSIBM1160",
  "CSIBM1161",
  "CSIBM1163",
  "CSIBM1164",
  "CSIBM11621162",
  "CSISO4UNITEDKINGDOM",
  "CSISO10SWEDISH",
  "CSISO11SWEDISHFORNAMES",
  "CSISO14JISC6220RO",
  "CSISO15ITALIAN",
  "CSISO16PORTUGESE",
  "CSISO17SPANISH",
  "CSISO18GREEK7OLD",
  "CSISO19LATINGREEK",
  "CSISO21GERMAN",
  "CSISO25FRENCH",
  "CSISO27LATINGREEK1",
  "CSISO49INIS",
  "CSISO50INIS8",
  "CSISO51INISCYRILLIC",
  "CSISO58GB1988",
  "CSISO60DANISHNORWEGIAN",
  "CSISO60NORWEGIAN1",
  "CSISO61NORWEGIAN2",
  "CSISO69FRENCH",
  "CSISO84PORTUGUESE2",
  "CSISO85SPANISH2",
  "CSISO86HUNGARIAN",
  "CSISO88GREEK7",
  "CSISO89ASMO449",
  "CSISO90",
  "CSISO92JISC62991984B",
  "CSISO99NAPLPS",
  "CSISO103T618BIT",
  "CSISO111ECMACYRILLIC",
  "CSISO121CANADIAN1",
  "CSISO122CANADIAN2",
  "CSISO139CSN369103",
  "CSISO141JUSIB1002",
  "CSISO143IECP271",
  "CSISO150",
  "CSISO150GREEKCCITT",
  "CSISO151CUBA",
  "CSISO153GOST1976874",
  "CSISO646DANISH",
  "CSISO2022CN",
  "CSISO2022JP",
  "CSISO2022JP2",
  "CSISO2022KR",
  "CSISO2033",
  "CSISO5427CYRILLIC",
  "CSISO5427CYRILLIC1981",
  "CSISO5428GREEK",
  "CSISO10367BOX",
  "CSISOLATIN1",
  "CSISOLATIN2",
  "CSISOLATIN3",
  "CSISOLATIN4",
  "CSISOLATIN5",
  "CSISOLATIN6",
  "CSISOLATINARABIC",
  "CSISOLATINCYRILLIC",
  "CSISOLATINGREEK",
  "CSISOLATINHEBREW",
  "CSKOI8R",
  "CSKSC5636",
  "CSMACINTOSH",
  "CSNATSDANO",
  "CSNATSSEFI",
  "CSN_369103",
  "CSPC8CODEPAGE437",
  "CSPC775BALTIC",
  "CSPC850MULTILINGUAL",
  "CSPC862LATINHEBREW",
  "CSPCP852",
  "CSSHIFTJIS",
  "CSUCS4",
  "CSUNICODE",
  "CUBA",
  "CWI-2",
  "CWI",
  "CYRILLIC",
  "DE",
  "DEC-MCS",
  "DEC",
  "DECMCS",
  "DIN_66003",
  "DK",
  "DS2089",
  "DS_2089",
  "E13B",
  "EBCDIC-AT-DE-A",
  "EBCDIC-AT-DE",
  "EBCDIC-BE",
  "EBCDIC-BR",
  "EBCDIC-CA-FR",
  "EBCDIC-CP-AR1",
  "EBCDIC-CP-AR2",
  "EBCDIC-CP-BE",
  "EBCDIC-CP-CA",
  "EBCDIC-CP-CH",
  "EBCDIC-CP-DK",
  "EBCDIC-CP-ES",
  "EBCDIC-CP-FI",
  "EBCDIC-CP-FR",
  "EBCDIC-CP-GB",
  "EBCDIC-CP-GR",
  "EBCDIC-CP-HE",
  "EBCDIC-CP-IS",
  "EBCDIC-CP-IT",
  "EBCDIC-CP-NL",
  "EBCDIC-CP-NO",
  "EBCDIC-CP-ROECE",
  "EBCDIC-CP-SE",
  "EBCDIC-CP-TR",
  "EBCDIC-CP-US",
  "EBCDIC-CP-WT",
  "EBCDIC-CP-YU",
  "EBCDIC-CYRILLIC",
  "EBCDIC-DK-NO-A",
  "EBCDIC-DK-NO",
  "EBCDIC-ES-A",
  "EBCDIC-ES-S",
  "EBCDIC-ES",
  "EBCDIC-FI-SE-A",
  "EBCDIC-FI-SE",
  "EBCDIC-FR",
  "EBCDIC-GREEK",
  "EBCDIC-INT",
  "EBCDIC-INT1",
  "EBCDIC-IS-FRISS",
  "EBCDIC-IT",
  "EBCDIC-JP-E",
  "EBCDIC-JP-KANA",
  "EBCDIC-PT",
  "EBCDIC-UK",
  "EBCDIC-US",
  "EBCDICATDE",
  "EBCDICATDEA",
  "EBCDICCAFR",
  "EBCDICDKNO",
  "EBCDICDKNOA",
  "EBCDICES",
  "EBCDICESA",
  "EBCDICESS",
  "EBCDICFISE",
  "EBCDICFISEA",
  "EBCDICFR",
  "EBCDICISFRISS",
  "EBCDICIT",
  "EBCDICPT",
  "EBCDICUK",
  "EBCDICUS",
  "ECMA-114",
  "ECMA-118",
  "ECMA-128",
  "ECMA-CYRILLIC",
  "ECMACYRILLIC",
  "ELOT_928",
  "ES",
  "ES2",
  "EUC-CN",
  "EUC-JISX0213",
  "EUC-JP",
  "EUC-KR",
  "EUC-TW",
  "EUCCN",
  "EUCJP",
  "EUCKR",
  "EUCTW",
  "FI",
  "FR",
  "GB",
  "GB2312",
  "GB13000",
  "GB18030",
  "GBK",
  "GB_1988-80",
  "GB_198880",
  "GEORGIAN-ACADEMY",
  "GEORGIAN-PS",
  "GOST_19768-74",
  "GOST_19768",
  "GOST_1976874",
  "GREEK-CCITT",
  "GREEK",
  "GREEK7-OLD",
  "GREEK7",
  "GREEK7OLD",
  "GREEK8",
  "GREEKCCITT",
  "HEBREW",
  "HP-ROMAN8",
  "HPROMAN8",
  "HU",
  "IBM-856",
  "IBM-922",
  "IBM-930",
  "IBM-932",
  "IBM-933",
  "IBM-935",
  "IBM-937",
  "IBM-939",
  "IBM-943",
  "IBM-1046",
  "IBM-1124",
  "IBM-1129",
  "IBM-1132",
  "IBM-1133",
  "IBM-1160",
  "IBM-1161",
  "IBM-1162",
  "IBM-1163",
  "IBM-1164",
  "IBM037",
  "IBM038",
  "IBM256",
  "IBM273",
  "IBM274",
  "IBM275",
  "IBM277",
  "IBM278",
  "IBM280",
  "IBM281",
  "IBM284",
  "IBM285",
  "IBM290",
  "IBM297",
  "IBM367",
  "IBM420",
  "IBM423",
  "IBM424",
  "IBM437",
  "IBM500",
  "IBM775",
  "IBM813",
  "IBM819",
  "IBM848",
  "IBM850",
  "IBM851",
  "IBM852",
  "IBM855",
  "IBM856",
  "IBM857",
  "IBM860",
  "IBM861",
  "IBM862",
  "IBM863",
  "IBM864",
  "IBM865",
  "IBM866",
  "IBM868",
  "IBM869",
  "IBM870",
  "IBM871",
  "IBM874",
  "IBM875",
  "IBM880",
  "IBM891",
  "IBM903",
  "IBM904",
  "IBM905",
  "IBM912",
  "IBM915",
  "IBM916",
  "IBM918",
  "IBM920",
  "IBM922",
  "IBM930",
  "IBM932",
  "IBM933",
  "IBM935",
  "IBM937",
  "IBM939",
  "IBM943",
  "IBM1004",
  "IBM1026",
  "IBM1046",
  "IBM1047",
  "IBM1089",
  "IBM1124",
  "IBM1129",
  "IBM1132",
  "IBM1133",
  "IBM1160",
  "IBM1161",
  "IBM1162",
  "IBM1163",
  "IBM1164",
  "IEC_P27-1",
  "IEC_P271",
  "INIS-8",
  "INIS-CYRILLIC",
  "INIS",
  "INIS8",
  "INISCYRILLIC",
  "ISIRI-3342",
  "ISIRI3342",
  "ISO-2022-CN-EXT",
  "ISO-2022-CN",
  "ISO-2022-JP-2",
  "ISO-2022-JP-3",
  "ISO-2022-JP",
  "ISO-2022-KR",
  "ISO-8859-1",
  "ISO-8859-2",
  "ISO-8859-3",
  "ISO-8859-4",
  "ISO-8859-5",
  "ISO-8859-6",
  "ISO-8859-7",
  "ISO-8859-8",
  "ISO-8859-9",
  "ISO-8859-10",
  "ISO-8859-11",
  "ISO-8859-13",
  "ISO-8859-14",
  "ISO-8859-15",
  "ISO-8859-16",
  "ISO-10646",
  "ISO-10646UCS2",
  "ISO-10646UCS4",
  "ISO-10646UTF-8",
  "ISO-10646UTF8",
  "ISO-CELTIC",
  "ISO-IR-4",
  "ISO-IR-6",
  "ISO-IR-8-1",
  "ISO-IR-9-1",
  "ISO-IR-10",
  "ISO-IR-11",
  "ISO-IR-14",
  "ISO-IR-15",
  "ISO-IR-16",
  "ISO-IR-17",
  "ISO-IR-18",
  "ISO-IR-19",
  "ISO-IR-21",
  "ISO-IR-25",
  "ISO-IR-27",
  "ISO-IR-37",
  "ISO-IR-49",
  "ISO-IR-50",
  "ISO-IR-51",
  "ISO-IR-54",
  "ISO-IR-55",
  "ISO-IR-57",
  "ISO-IR-60",
  "ISO-IR-61",
  "ISO-IR-69",
  "ISO-IR-84",
  "ISO-IR-85",
  "ISO-IR-86",
  "ISO-IR-88",
  "ISO-IR-89",
  "ISO-IR-90",
  "ISO-IR-92",
  "ISO-IR-98",
  "ISO-IR-99",
  "ISO-IR-100",
  "ISO-IR-101",
  "ISO-IR-103",
  "ISO-IR-109",
  "ISO-IR-110",
  "ISO-IR-111",
  "ISO-IR-121",
  "ISO-IR-122",
  "ISO-IR-126",
  "ISO-IR-127",
  "ISO-IR-138",
  "ISO-IR-139",
  "ISO-IR-141",
  "ISO-IR-143",
  "ISO-IR-144",
  "ISO-IR-148",
  "ISO-IR-150",
  "ISO-IR-151",
  "ISO-IR-153",
  "ISO-IR-155",
  "ISO-IR-156",
  "ISO-IR-157",
  "ISO-IR-166",
  "ISO-IR-179",
  "ISO-IR-193",
  "ISO-IR-197",
  "ISO-IR-199",
  "ISO-IR-203",
  "ISO-IR-209",
  "ISO-IR-226",
  "ISO646-CA",
  "ISO646-CA2",
  "ISO646-CN",
  "ISO646-CU",
  "ISO646-DE",
  "ISO646-DK",
  "ISO646-ES",
  "ISO646-ES2",
  "ISO646-FI",
  "ISO646-FR",
  "ISO646-FR1",
  "ISO646-GB",
  "ISO646-HU",
  "ISO646-IT",
  "ISO646-JP-OCR-B",
  "ISO646-JP",
  "ISO646-KR",
  "ISO646-NO",
  "ISO646-NO2",
  "ISO646-PT",
  "ISO646-PT2",
  "ISO646-SE",
  "ISO646-SE2",
  "ISO646-US",
  "ISO646-YU",
  "ISO2022CN",
  "ISO2022CNEXT",
  "ISO2022JP",
  "ISO2022JP2",
  "ISO2022KR",
  "ISO6937",
  "ISO8859-1",
  "ISO8859-2",
  "ISO8859-3",
  "ISO8859-4",
  "ISO8859-5",
  "ISO8859-6",
  "ISO8859-7",
  "ISO8859-8",
  "ISO8859-9",
  "ISO8859-10",
  "ISO8859-11",
  "ISO8859-13",
  "ISO8859-14",
  "ISO8859-15",
  "ISO8859-16",
  "ISO88591",
  "ISO88592",
  "ISO88593",
  "ISO88594",
  "ISO88595",
  "ISO88596",
  "ISO88597",
  "ISO88598",
  "ISO88599",
  "ISO885910",
  "ISO885911",
  "ISO885913",
  "ISO885914",
  "ISO885915",
  "ISO885916",
  "ISO_646.IRV:1991",
  "ISO_2033-1983",
  "ISO_2033",
  "ISO_5427-EXT",
  "ISO_5427",
  "ISO_5427:1981",
  "ISO_5427EXT",
  "ISO_5428",
  "ISO_5428:1980",
  "ISO_6937-2",
  "ISO_6937-2:1983",
  "ISO_6937",
  "ISO_6937:1992",
  "ISO_8859-1",
  "ISO_8859-1:1987",
  "ISO_8859-2",
  "ISO_8859-2:1987",
  "ISO_8859-3",
  "ISO_8859-3:1988",
  "ISO_8859-4",
  "ISO_8859-4:1988",
  "ISO_8859-5",
  "ISO_8859-5:1988",
  "ISO_8859-6",
  "ISO_8859-6:1987",
  "ISO_8859-7",
  "ISO_8859-7:1987",
  "ISO_8859-8",
  "ISO_8859-8:1988",
  "ISO_8859-9",
  "ISO_8859-9:1989",
  "ISO_8859-10",
  "ISO_8859-10:1992",
  "ISO_8859-14",
  "ISO_8859-14:1998",
  "ISO_8859-15:1998",
  "ISO_9036",
  "ISO_10367-BOX",
  "ISO_10367BOX",
  "ISO_69372",
  "IT",
  "JIS_C6220-1969-RO",
  "JIS_C6229-1984-B",
  "JIS_C62201969RO",
  "JIS_C62291984B",
  "JOHAB",
  "JP-OCR-B",
  "JP",
  "JS",
  "JUS_I.B1.002",
  "KOI-7",
  "KOI-8",
  "KOI8-R",
  "KOI8-T",
  "KOI8-U",
  "KOI8",
  "KOI8R",
  "KOI8U",
  "KSC5636",
  "L1",
  "L2",
  "L3",
  "L4",
  "L5",
  "L6",
  "L7",
  "L8",
  "L10",
  "LATIN-GREEK-1",
  "LATIN-GREEK",
  "LATIN1",
  "LATIN2",
  "LATIN3",
  "LATIN4",
  "LATIN5",
  "LATIN6",
  "LATIN7",
  "LATIN8",
  "LATIN10",
  "LATINGREEK",
  "LATINGREEK1",
  "MAC-CYRILLIC",
  "MAC-IS",
  "MAC-SAMI",
  "MAC-UK",
  "MAC",
  "MACCYRILLIC",
  "MACINTOSH",
  "MACIS",
  "MACUK",
  "MACUKRAINIAN",
  "MS-ANSI",
  "MS-ARAB",
  "MS-CYRL",
  "MS-EE",
  "MS-GREEK",
  "MS-HEBR",
  "MS-MAC-CYRILLIC",
  "MS-TURK",
  "MSCP949",
  "MSCP1361",
  "MSMACCYRILLIC",
  "MSZ_7795.3",
  "MS_KANJI",
  "NAPLPS",
  "NATS-DANO",
  "NATS-SEFI",
  "NATSDANO",
  "NATSSEFI",
  "NC_NC0010",
  "NC_NC00-10",
  "NC_NC00-10:81",
  "NF_Z_62-010",
  "NF_Z_62-010_(1973)",
  "NF_Z_62-010_1973",
  "NF_Z_62010",
  "NF_Z_62010_1973",
  "NO",
  "NO2",
  "NS_4551-1",
  "NS_4551-2",
  "NS_45511",
  "NS_45512",
  "OS2LATIN1",
  "OSF00010001",
  "OSF00010002",
  "OSF00010003",
  "OSF00010004",
  "OSF00010005",
  "OSF00010006",
  "OSF00010007",
  "OSF00010008",
  "OSF00010009",
  "OSF0001000A",
  "OSF00010020",
  "OSF00010100",
  "OSF00010101",
  "OSF00010102",
  "OSF00010104",
  "OSF00010105",
  "OSF00010106",
  "OSF00030010",
  "OSF0004000A",
  "OSF0005000A",
  "OSF05010001",
  "OSF100201A4",
  "OSF100201A8",
  "OSF100201B5",
  "OSF100201F4",
  "OSF100203B5",
  "OSF1002011C",
  "OSF1002011D",
  "OSF1002035D",
  "OSF1002035E",
  "OSF1002035F",
  "OSF1002036B",
  "OSF1002037B",
  "OSF10010001",
  "OSF10020025",
  "OSF10020111",
  "OSF10020115",
  "OSF10020116",
  "OSF10020118",
  "OSF10020122",
  "OSF10020129",
  "OSF10020352",
  "OSF10020354",
  "OSF10020357",
  "OSF10020359",
  "OSF10020360",
  "OSF10020364",
  "OSF10020365",
  "OSF10020366",
  "OSF10020367",
  "OSF10020370",
  "OSF10020387",
  "OSF10020388",
  "OSF10020396",
  "OSF10020402",
  "OSF10020417",
  "PT",
  "PT2",
  "R8",
  "ROMAN8",
  "RUSCII",
  "SE",
  "SE2",
  "SEN_850200_B",
  "SEN_850200_C",
  "SHIFT-JIS",
  "SHIFT_JIS",
  "SHIFT_JISX0213",
  "SJIS",
  "SS636127",
  "ST_SEV_358-88",
  "T.61-8BIT",
  "T.61",
  "T.618BIT",
  "TCVN-5712",
  "TCVN",
  "TCVN5712-1",
  "TCVN5712-1:1993",
  "TIS-620",
  "TIS620-0",
  "TIS620.2529-1",
  "TIS620.2533-0",
  "TIS620",
  "TS-5881",
  "TSCII",
  "UCS-2",
  "UCS-2BE",
  "UCS-2LE",
  "UCS-4",
  "UCS-4BE",
  "UCS-4LE",
  "UCS2",
  "UCS4",
  "UHC",
  "UJIS",
  "UK",
  "UNICODE",
  "UNICODEBIG",
  "UNICODELITTLE",
  "US-ASCII",
  "US",
  "UTF-7",
  "UTF-8",
  "UTF-16",
  "UTF-16BE",
  "UTF-16LE",
  "UTF-32",
  "UTF-32BE",
  "UTF-32LE",
  "UTF7",
  "UTF8",
  "UTF16",
  "UTF16BE",
  "UTF16LE",
  "UTF32",
  "UTF32BE",
  "UTF32LE",
  "VISCII",
  "WCHAR_T",
  "WIN-SAMI-2",
  "WINBALTRIM",
  "WINDOWS-1250",
  "WINDOWS-1251",
  "WINDOWS-1252",
  "WINDOWS-1253",
  "WINDOWS-1254",
  "WINDOWS-1255",
  "WINDOWS-1256",
  "WINDOWS-1257",
  "WINDOWS-1258",
  "WINSAMI2",
  "WS2",
  "YU",
  NULL
};
#else
const char *sub_charsets[] = {
  "437",
  "850",
  "852",
  "855",
  "857",
  "860",
  "861",
  "862",
  "863",
  "865",
  "866",
  "869",
  "ANSI_X3.4-1968",
  "ANSI_X3.4-1986",
  "ARABIC",
  "ARMSCII-8",
  "ASCII",
  "ASMO-708",
  "BIG-5",
  "BIG-FIVE",
  "BIG5",
  "BIG5-HKSCS",
  "BIG5HKSCS",
  "BIGFIVE",
  "C99",
  "CHINESE",
  "CN",
  "CN-BIG5",
  "CN-GB",
  "CN-GB-ISOIR165",
  "CP-GR",
  "CP-IS",
  "CP1125",
  "CP1133",
  "CP1250",
  "CP1251",
  "CP1252",
  "CP1253",
  "CP1254",
  "CP1255",
  "CP1256",
  "CP1257",
  "CP1258",
  "CP1361",
  "CP367",
  "CP437",
  "CP737",
  "CP775",
  "CP819",
  "CP850",
  "CP852",
  "CP853",
  "CP855",
  "CP857",
  "CP858",
  "CP860",
  "CP861",
  "CP862",
  "CP863",
  "CP864",
  "CP865",
  "CP866",
  "CP869",
  "CP874",
  "CP932",
  "CP936",
  "CP949",
  "CP950",
  "CSASCII",
  "CSBIG5",
  "CSEUCKR",
  "CSEUCPKDFMTJAPANESE",
  "CSEUCTW",
  "CSGB2312",
  "CSHALFWIDTHKATAKANA",
  "CSHPROMAN8",
  "CSIBM855",
  "CSIBM857",
  "CSIBM860",
  "CSIBM861",
  "CSIBM863",
  "CSIBM864",
  "CSIBM865",
  "CSIBM866",
  "CSIBM869",
  "CSISO14JISC6220RO",
  "CSISO159JISX02121990",
  "CSISO2022CN",
  "CSISO2022JP",
  "CSISO2022JP2",
  "CSISO2022KR",
  "CSISO57GB1988",
  "CSISO58GB231280",
  "CSISO87JISX0208",
  "CSISOLATIN1",
  "CSISOLATIN2",
  "CSISOLATIN3",
  "CSISOLATIN4",
  "CSISOLATIN5",
  "CSISOLATIN6",
  "CSISOLATINARABIC",
  "CSISOLATINCYRILLIC",
  "CSISOLATINGREEK",
  "CSISOLATINHEBREW",
  "CSKOI8R",
  "CSKSC56011987",
  "CSMACINTOSH",
  "CSPC775BALTIC",
  "CSPC850MULTILINGUAL",
  "CSPC862LATINHEBREW",
  "CSPC8CODEPAGE437",
  "CSPCP852",
  "CSSHIFTJIS",
  "CSUCS4",
  "CSUNICODE",
  "CSUNICODE11",
  "CSUNICODE11UTF7",
  "CSVISCII",
  "CYRILLIC",
  "ECMA-114",
  "ECMA-118",
  "ELOT_928",
  "EUC-CN",
  "EUC-JP",
  "EUC-KR",
  "EUC-TW",
  "EUCCN",
  "EUCJP",
  "EUCKR",
  "EUCTW",
  "EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE",
  "GB18030",
  "GB2312",
  "GBK",
  "GB_1988-80",
  "GB_2312-80",
  "GEORGIAN-ACADEMY",
  "GEORGIAN-PS",
  "GREEK",
  "GREEK8",
  "HEBREW",
  "HP-ROMAN8",
  "HZ",
  "HZ-GB-2312",
  "IBM-CP1133",
  "IBM367",
  "IBM437",
  "IBM775",
  "IBM819",
  "IBM850",
  "IBM852",
  "IBM855",
  "IBM857",
  "IBM860",
  "IBM861",
  "IBM862",
  "IBM863",
  "IBM864",
  "IBM865",
  "IBM866",
  "IBM869",
  "ISO-10646-UCS-2",
  "ISO-10646-UCS-4",
  "ISO-2022-CN",
  "ISO-2022-CN-EXT",
  "ISO-2022-JP",
  "ISO-2022-JP-1",
  "ISO-2022-JP-2",
  "ISO-2022-KR",
  "ISO-8859-1",
  "ISO-8859-10",
  "ISO-8859-13",
  "ISO-8859-14",
  "ISO-8859-15",
  "ISO-8859-16",
  "ISO-8859-2",
  "ISO-8859-3",
  "ISO-8859-4",
  "ISO-8859-5",
  "ISO-8859-6",
  "ISO-8859-7",
  "ISO-8859-8",
  "ISO-8859-9",
  "ISO-CELTIC",
  "ISO-IR-100",
  "ISO-IR-101",
  "ISO-IR-109",
  "ISO-IR-110",
  "ISO-IR-126",
  "ISO-IR-127",
  "ISO-IR-138",
  "ISO-IR-14",
  "ISO-IR-144",
  "ISO-IR-148",
  "ISO-IR-149",
  "ISO-IR-157",
  "ISO-IR-159",
  "ISO-IR-165",
  "ISO-IR-166",
  "ISO-IR-179",
  "ISO-IR-199",
  "ISO-IR-203",
  "ISO-IR-226",
  "ISO-IR-57",
  "ISO-IR-58",
  "ISO-IR-6",
  "ISO-IR-87",
  "ISO646-CN",
  "ISO646-JP",
  "ISO646-US",
  "ISO_646.IRV:1991",
  "ISO_8859-1",
  "ISO_8859-10",
  "ISO_8859-10:1992",
  "ISO_8859-13",
  "ISO_8859-14",
  "ISO_8859-14:1998",
  "ISO_8859-15",
  "ISO_8859-15:1998",
  "ISO_8859-16",
  "ISO_8859-16:2000",
  "ISO_8859-1:1987",
  "ISO_8859-2",
  "ISO_8859-2:1987",
  "ISO_8859-3",
  "ISO_8859-3:1988",
  "ISO_8859-4",
  "ISO_8859-4:1988",
  "ISO_8859-5",
  "ISO_8859-5:1988",
  "ISO_8859-6",
  "ISO_8859-6:1987",
  "ISO_8859-7",
  "ISO_8859-7:1987",
  "ISO_8859-8",
  "ISO_8859-8:1988",
  "ISO_8859-9",
  "ISO_8859-9:1989",
  "JAVA",
  "JIS0208",
  "JISX0201-1976",
  "JIS_C6220-1969-RO",
  "JIS_C6226-1983",
  "JIS_X0201",
  "JIS_X0208",
  "JIS_X0208-1983",
  "JIS_X0208-1990",
  "JIS_X0212",
  "JIS_X0212-1990",
  "JIS_X0212.1990-0",
  "JOHAB",
  "JP",
  "KOI8-R",
  "KOI8-RU",
  "KOI8-T",
  "KOI8-U",
  "KOREAN",
  "KSC_5601",
  "KS_C_5601-1987",
  "KS_C_5601-1989",
  "L1",
  "L2",
  "L3",
  "L4",
  "L5",
  "L6",
  "L7",
  "L8",
  "LATIN1",
  "LATIN2",
  "LATIN3",
  "LATIN4",
  "LATIN5",
  "LATIN6",
  "LATIN7",
  "LATIN8",
  "MAC",
  "MACARABIC",
  "MACCENTRALEUROPE",
  "MACCROATIAN",
  "MACCYRILLIC",
  "MACGREEK",
  "MACHEBREW",
  "MACICELAND",
  "MACINTOSH",
  "MACROMAN",
  "MACROMANIA",
  "MACTHAI",
  "MACTURKISH",
  "MACUKRAINE",
  "MS-ANSI",
  "MS-ARAB",
  "MS-CYRL",
  "MS-EE",
  "MS-GREEK",
  "MS-HEBR",
  "MS-TURK",
  "MS_KANJI",
  "MULELAO-1",
  "NEXTSTEP",
  "R8",
  "ROMAN8",
  "SHIFT-JIS",
  "SHIFT_JIS",
  "SJIS",
  "TCVN",
  "TCVN-5712",
  "TCVN5712-1",
  "TCVN5712-1:1993",
  "TIS-620",
  "TIS620",
  "TIS620-0",
  "TIS620.2529-1",
  "TIS620.2533-0",
  "TIS620.2533-1",
  "UCS-2",
  "UCS-2-INTERNAL",
  "UCS-2-SWAPPED",
  "UCS-2BE",
  "UCS-2LE",
  "UCS-4",
  "UCS-4-INTERNAL",
  "UCS-4-SWAPPED",
  "UCS-4BE",
  "UCS-4LE",
  "UHC",
  "UNICODE-1-1",
  "UNICODE-1-1-UTF-7",
  "UNICODEBIG",
  "UNICODELITTLE",
  "US",
  "US-ASCII",
  "UTF-16",
  "UTF-16BE",
  "UTF-16LE",
  "UTF-32",
  "UTF-32BE",
  "UTF-32LE",
  "UTF-7",
  "UTF-8",
  "VISCII",
  "VISCII1.1-1",
  "WINBALTRIM",
  "WINDOWS-1250",
  "WINDOWS-1251",
  "WINDOWS-1252",
  "WINDOWS-1253",
  "WINDOWS-1254",
  "WINDOWS-1255",
  "WINDOWS-1256",
  "WINDOWS-1257",
  "WINDOWS-1258",
  "WINDOWS-874",
  "X0201",
  "X0208",
  "X0212",
  NULL
};
#endif

const char *mime_types[] = {
  "text/plain",
  "text/richtext",
  "text/enriched",
  "text/tab-separated-values",
  "text/html",
  "text/sgml",
  "text/vnd.latex-z",
  "text/vnd.fmi.flexstor",
  "text/uri-list",
  "text/vnd.abc",
  "text/rfc822-headers",
  "text/vnd.in3d.3dml",
  "text/prs.lines.tag",
  "text/vnd.in3d.spot",
  "text/css",
  "text/xml",
  "text/xml-external-parsed-entity",
  "text/rtf",
  "text/directory",
  "text/calendar",
  "text/vnd.wap.wml",
  "text/vnd.wap.wmlscript",
  "text/vnd.motorola.reflex",
  "text/vnd.fly",
  "text/vnd.wap.sl",
  "text/vnd.wap.si",
  "text/t140",
  "text/vnd.ms-mediapackage",
  "text/vnd.IPTC.NewsML",
  "text/vnd.IPTC.NITF",
  "text/vnd.curl",
  "text/vnd.DMClientScript",
  "text/parityfec",
  "multipart/mixed",
  "multipart/alternative",
  "multipart/digest",
  "multipart/parallel",
  "multipart/appledouble",
  "multipart/header-set",
  "multipart/form-data",
  "multipart/related",
  "multipart/report",
  "multipart/voice-message",
  "multipart/signed",
  "multipart/encrypted",
  "multipart/byteranges",
  "message/rfc822",
  "message/partial",
  "message/external-body",
  "message/news",
  "message/http",
  "message/delivery-status",
  "message/disposition-notification",
  "message/s-http",
  "application/octet-stream",
  "application/postscript",
  "application/oda",
  "application/atomicmail",
  "application/andrew-inset",
  "application/slate",
  "application/wita",
  "application/dec-dx",
  "application/dca-rft",
  "application/activemessage",
  "application/rtf",
  "application/applefile",
  "application/mac-binhex40",
  "application/news-message-id",
  "application/news-transmission",
  "application/wordperfect5.1",
  "application/pdf",
  "application/zip",
  "application/macwriteii",
  "application/msword",
  "application/remote-printing",
  "application/mathematica",
  "application/cybercash",
  "application/commonground",
  "application/iges",
  "application/riscos",
  "application/eshop",
  "application/x400-bp",
  "application/sgml",
  "application/cals-1840",
  "application/pgp-encrypted",
  "application/pgp-signature",
  "application/pgp-keys",
  "application/vnd.framemaker",
  "application/vnd.mif",
  "application/vnd.ms-excel",
  "application/vnd.ms-powerpoint",
  "application/vnd.ms-project",
  "application/vnd.ms-works",
  "application/vnd.ms-tnef",
  "application/vnd.svd",
  "application/vnd.music-niff",
  "application/vnd.ms-artgalry",
  "application/vnd.truedoc",
  "application/vnd.koan",
  "application/vnd.street-stream",
  "application/vnd.fdf",
  "application/set-payment-initiation",
  "application/set-payment",
  "application/set-registration-initiation",
  "application/set-registration",
  "application/vnd.seemail",
  "application/vnd.businessobjects",
  "application/vnd.meridian-slingshot",
  "application/vnd.xara",
  "application/sgml-open-catalog",
  "application/vnd.rapid",
  "application/vnd.enliven",
  "application/vnd.japannet-registration-wakeup",
  "application/vnd.japannet-verification-wakeup",
  "application/vnd.japannet-payment-wakeup",
  "application/vnd.japannet-directory-service",
  "application/vnd.intertrust.digibox",
  "application/vnd.intertrust.nncp",
  "application/prs.alvestrand.titrax-sheet",
  "application/vnd.noblenet-web",
  "application/vnd.noblenet-sealer",
  "application/vnd.noblenet-directory",
  "application/prs.nprend",
  "application/vnd.webturbo",
  "application/hyperstudio",
  "application/vnd.shana.informed.formtemplate",
  "application/vnd.shana.informed.formdata",
  "application/vnd.shana.informed.package",
  "application/vnd.shana.informed.interchange",
  "application/vnd.$commerce_battelle",
  "application/vnd.osa.netdeploy",
  "application/vnd.ibm.MiniPay",
  "application/vnd.japannet-jpnstore-wakeup",
  "application/vnd.japannet-setstore-wakeup",
  "application/vnd.japannet-verification",
  "application/vnd.japannet-registration",
  "application/vnd.hp-HPGL",
  "application/vnd.hp-PCL",
  "application/vnd.hp-PCLXL",
  "application/vnd.musician",
  "application/vnd.FloGraphIt",
  "application/vnd.intercon.formnet",
  "application/vemmi",
  "application/vnd.ms-asf",
  "application/vnd.ecdis-update",
  "application/vnd.powerbuilder6",
  "application/vnd.powerbuilder6-s",
  "application/vnd.lotus-wordpro",
  "application/vnd.lotus-approach",
  "application/vnd.lotus-1-2-3",
  "application/vnd.lotus-organizer",
  "application/vnd.lotus-screencam",
  "application/vnd.lotus-freelance",
  "application/vnd.fujitsu.oasys",
  "application/vnd.fujitsu.oasys2",
  "application/vnd.swiftview-ics",
  "application/vnd.dna",
  "application/prs.cww",
  "application/vnd.wt.stf",
  "application/vnd.dxr",
  "application/vnd.mitsubishi.misty-guard.trustweb",
  "application/vnd.ibm.modcap",
  "application/vnd.acucobol",
  "application/vnd.fujitsu.oasys3",
  "application/marc",
  "application/vnd.fujitsu.oasysprs",
  "application/vnd.fujitsu.oasysgp",
  "application/vnd.visio",
  "application/vnd.netfpx",
  "application/vnd.audiograph",
  "application/vnd.epson.salt",
  "application/vnd.3M.Post-it-Notes",
  "application/vnd.novadigm.EDX",
  "application/vnd.novadigm.EXT",
  "application/vnd.novadigm.EDM",
  "application/vnd.claymore",
  "application/vnd.comsocaller",
  "application/pkcs7-mime",
  "application/pkcs7-signature",
  "application/pkcs10",
  "application/vnd.yellowriver-custom-menu",
  "application/vnd.ecowin.chart",
  "application/vnd.ecowin.series",
  "application/vnd.ecowin.filerequest",
  "application/vnd.ecowin.fileupdate",
  "application/vnd.ecowin.seriesrequest",
  "application/vnd.ecowin.seriesupdate",
  "application/EDIFACT",
  "application/EDI-X12",
  "application/EDI-Consent",
  "application/vnd.wrq-hp3000-labelled",
  "application/vnd.minisoft-hp3000-save",
  "application/vnd.ffsns",
  "application/vnd.hp-hps",
  "application/vnd.fujixerox.docuworks",
  "application/xml",
  "application/xml-external-parsed-entity",
  "application/xml-dtd",
  "application/vnd.anser-web-funds-transfer-initiation",
  "application/vnd.anser-web-certificate-issue-initiation",
  "application/vnd.is-xpr",
  "application/vnd.intu.qbo",
  "application/vnd.publishare-delta-tree",
  "application/vnd.cybank",
  "application/batch-SMTP",
  "application/vnd.uplanet.alert",
  "application/vnd.uplanet.cacheop",
  "application/vnd.uplanet.list",
  "application/vnd.uplanet.listcmd",
  "application/vnd.uplanet.channel",
  "application/vnd.uplanet.bearer-choice",
  "application/vnd.uplanet.signal",
  "application/vnd.uplanet.alert-wbxml",
  "application/vnd.uplanet.cacheop-wbxml",
  "application/vnd.uplanet.list-wbxml",
  "application/vnd.uplanet.listcmd-wbxml",
  "application/vnd.uplanet.channel-wbxml",
  "application/vnd.uplanet.bearer-choice-wbxml",
  "application/vnd.epson.quickanime",
  "application/vnd.commonspace",
  "application/vnd.fut-misnet",
  "application/vnd.xfdl",
  "application/vnd.intu.qfx",
  "application/vnd.epson.ssf",
  "application/vnd.epson.msf",
  "application/vnd.powerbuilder7",
  "application/vnd.powerbuilder7-s",
  "application/vnd.lotus-notes",
  "application/pkixcmp",
  "application/vnd.wap.wmlc",
  "application/vnd.wap.wmlscriptc",
  "application/vnd.motorola.flexsuite",
  "application/vnd.wap.wbxml",
  "application/vnd.motorola.flexsuite.wem",
  "application/vnd.motorola.flexsuite.kmr",
  "application/vnd.motorola.flexsuite.adsi",
  "application/vnd.motorola.flexsuite.fis",
  "application/vnd.motorola.flexsuite.gotap",
  "application/vnd.motorola.flexsuite.ttc",
  "application/vnd.ufdl",
  "application/vnd.accpac.simply.imp",
  "application/vnd.accpac.simply.aso",
  "application/vnd.vcx",
  "application/ipp",
  "application/ocsp-request",
  "application/ocsp-response",
  "application/vnd.previewsystems.box",
  "application/vnd.mediastation.cdkey",
  "application/vnd.pg.format",
  "application/vnd.pg.osasli",
  "application/vnd.hp-hpid",
  "application/pkix-cert",
  "application/pkix-crl",
  "application/vnd.Mobius.TXF",
  "application/vnd.Mobius.PLC",
  "application/vnd.Mobius.DIS",
  "application/vnd.Mobius.DAF",
  "application/vnd.Mobius.MSL",
  "application/vnd.cups-raster",
  "application/vnd.cups-postscript",
  "application/vnd.cups-raw",
  "application/index",
  "application/index.cmd",
  "application/index.response",
  "application/index.obj",
  "application/index.vnd",
  "application/vnd.triscape.mxs",
  "application/vnd.powerbuilder75",
  "application/vnd.powerbuilder75-s",
  "application/vnd.dpgraph",
  "application/http",
  "application/sdp",
  "application/vnd.eudora.data",
  "application/vnd.fujixerox.docuworks.binder",
  "application/vnd.vectorworks",
  "application/vnd.grafeq",
  "application/vnd.bmi",
  "application/vnd.ericsson.quickcall",
  "application/vnd.hzn-3d-crossword",
  "application/vnd.wap.slc",
  "application/vnd.wap.sic",
  "application/vnd.groove-injector",
  "application/vnd.fujixerox.ddd",
  "application/vnd.groove-account",
  "application/vnd.groove-identity-message",
  "application/vnd.groove-tool-message",
  "application/vnd.groove-tool-template",
  "application/vnd.groove-vcard",
  "application/vnd.ctc-posml",
  "application/vnd.canon-lips",
  "application/vnd.canon-cpdl",
  "application/vnd.trueapp",
  "application/vnd.s3sms",
  "application/iotp",
  "application/vnd.mcd",
  "application/vnd.httphone",
  "application/vnd.informix-visionary",
  "application/vnd.msign",
  "application/vnd.ms-lrm",
  "application/vnd.contact.cmsg",
  "application/vnd.epson.esf",
  "application/whoispp-query",
  "application/whoispp-response",
  "application/vnd.mozilla.xul+xml",
  "application/parityfec",
  "application/vnd.palm",
  "application/vnd.fsc.weblaunch",
  "application/vnd.tve-trigger",
  "application/dvcs",
  "application/sieve",
  "application/vnd.vividence.scriptfile",
  "application/vnd.hhe.lesson-player",
  "application/beep+xml",
  "application/font-tdpfr",
  "application/vnd.mseq",
  "application/vnd.aether.imp",
  "application/vnd.Mobius.MQY",
  "application/vnd.Mobius.MBK",
  "application/vnd.vidsoft.vidconference",
  "application/vnd.ibm.afplinedata",
  "application/vnd.irepository.package+xml",
  "application/vnd.sss-ntf",
  "application/vnd.sss-dtf",
  "application/vnd.sss-cod",
  "application/vnd.pvi.ptid1",
  "application/isup",
  "application/qsig",
  "application/timestamp-query",
  "application/timestamp-reply",
  "application/vnd.pwg-xhtml-print+xml",
  "image/jpeg",
  "image/gif",
  "image/iefImageExchangeFormat",
  "image/g3fax",
  "image/tiffTagImageFileFormat",
  "image/cgmComputerGraphicsMetafile",
  "image/naplps",
  "image/vnd.dwg",
  "image/vnd.svf",
  "image/vnd.dxf",
  "image/png",
  "image/vnd.fpx",
  "image/vnd.net-fpx",
  "image/vnd.xiff",
  "image/prs.btif",
  "image/vnd.fastbidsheet",
  "image/vnd.wap.wbmp",
  "image/prs.pti",
  "image/vnd.cns.inf2",
  "image/vnd.mix",
  "image/vnd.fujixerox.edmics-rlc",
  "image/vnd.fujixerox.edmics-mmr",
  "image/vnd.fst",
  "audio/basic",
  "audio/32kadpcm",
  "audio/vnd.qcelp",
  "audio/vnd.digital-winds",
  "audio/vnd.lucent.voice",
  "audio/vnd.octel.sbc",
  "audio/vnd.rhetorex.32kadpcm",
  "audio/vnd.vmx.cvsd",
  "audio/vnd.nortel.vbk",
  "audio/vnd.cns.anp1",
  "audio/vnd.cns.inf1",
  "audio/L16",
  "audio/vnd.everad.plj",
  "audio/telephone-event",
  "audio/tone",
  "audio/prs.sid",
  "audio/vnd.nuera.ecelp4800",
  "audio/vnd.nuera.ecelp7470",
  "audio/mpeg",
  "audio/parityfec",
  "audio/MP4A-LATM",
  "audio/vnd.nuera.ecelp9600",
  "audio/G.722.1",
  "audio/mpa-robust",
  "audio/vnd.cisco.nse",
  "audio/DAT12",
  "audio/L20",
  "audio/L24",
  "video/mpeg",
  "video/quicktime",
  "video/vnd.vivo",
  "video/vnd.motorola.video",
  "video/vnd.motorola.videop",
  "video/vnd.fvt",
  "video/pointer",
  "video/parityfec",
  "video/vnd.mpegurl",
  "video/MP4V-ES",
  "video/vnd.nokia.interleaved-multimedia",
  "model/iges",
  "model/vrml",
  "model/mesh",
  "model/vnd.dwf",
  "model/vnd.gtw",
  "model/vnd.flatland.3dml",
  "model/vnd.vtu",
  "model/vnd.mts",
  "model/vnd.gdl",
  "model/vnd.gs-gdl",
  "model/vnd.parasolid.transmit.text",
  "model/vnd.parasolid.transmit.binary",
  NULL
};

const char *cctlds[] = {
  "ac",
  "ad",
  "ae",
  "af",
  "ag",
  "ai",
  "al",
  "am",
  "an",
  "ao",
  "aq",
  "ar",
  "as",
  "at",
  "au",
  "aw",
  "az",
  "ba",
  "bb",
  "bd",
  "be",
  "bf",
  "bg",
  "bh",
  "bi",
  "bj",
  "bm",
  "bn",
  "bo",
  "br",
  "bs",
  "bt",
  "bv",
  "bw",
  "by",
  "bz",
  "ca",
  "cc",
  "cd",
  "cf",
  "cg",
  "ch",
  "ci",
  "ck",
  "cl",
  "cm",
  "cn",
  "co",
  "cr",
  "cu",
  "cv",
  "cx",
  "cy",
  "cz",
  "de",
  "dj",
  "dk",
  "dm",
  "do",
  "dz",
  "ec",
  "ee",
  "eg",
  "eh",
  "er",
  "es",
  "et",
  "fi",
  "fj",
  "fk",
  "fm",
  "fo",
  "fr",
  "ga",
  "gd",
  "ge",
  "gf",
  "gg",
  "gh",
  "gi",
  "gl",
  "gm",
  "gn",
  "gp",
  "gq",
  "gr",
  "gs",
  "gt",
  "gu",
  "gw",
  "gy",
  "hk",
  "hm",
  "hn",
  "hr",
  "ht",
  "hu",
  "id",
  "ie",
  "il",
  "im",
  "in",
  "io",
  "iq",
  "ir",
  "is",
  "it",
  "je",
  "jm",
  "jo",
  "jp",
  "ke",
  "kg",
  "kh",
  "ki",
  "km",
  "kn",
  "kp",
  "kr",
  "kw",
  "ky",
  "kz",
  "la",
  "lb",
  "lc",
  "li",
  "lk",
  "lr",
  "ls",
  "lt",
  "lu",
  "lv",
  "ly",
  "ma",
  "mc",
  "md",
  "mg",
  "mh",
  "mk",
  "ml",
  "mm",
  "mn",
  "mo",
  "mp",
  "mq",
  "mr",
  "ms",
  "mt",
  "mu",
  "mv",
  "mw",
  "mx",
  "my",
  "mz",
  "na",
  "nc",
  "ne",
  "nf",
  "ng",
  "ni",
  "nl",
  "no",
  "np",
  "nr",
  "nu",
  "nz",
  "om",
  "pa",
  "pe",
  "pf",
  "pg",
  "ph",
  "pk",
  "pl",
  "pm",
  "pn",
  "pr",
  "ps",
  "pt",
  "pw",
  "py",
  "qa",
  "re",
  "ro",
  "ru",
  "rw",
  "sa",
  "sb",
  "sc",
  "sd",
  "se",
  "sg",
  "sh",
  "si",
  "sj",
  "sk",
  "sl",
  "sm",
  "sn",
  "so",
  "sr",
  "st",
  "sv",
  "sy",
  "sz",
  "tc",
  "td",
  "tf",
  "tg",
  "th",
  "tj",
  "tk",
  "tm",
  "tn",
  "to",
  "tp",
  "tr",
  "tt",
  "tv",
  "tw",
  "tz",
  "ua",
  "ug",
  "uk",
  "um",
  "us",
  "uy",
  "uz",
  "va",
  "vc",
  "ve",
  "vg",
  "vi",
  "vn",
  "vu",
  "wf",
  "ws",
  "ye",
  "yt",
  "yu",
  "za",
  "zm",
  "zw",
  NULL
};
