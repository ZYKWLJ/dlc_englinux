// # ifndef _EG_FIND_HELP_H
// # define _EG_FIND_HELP_H
// #include "../display/eg_print_help.h"
// #define TOKEN1 "find"
// #define TOKEN1_DESC "必要指令，可简写为f"
// #define TOKEN2 "[%]word[%]"
// #define TOKEN2_DESC "必要指令，两端的%%为可选，word为精确查找，word%为查找以word为前缀的单词，%word为查找以word为后缀的单词，%word%为查找包含word的单词"
// #define TOKEN3 "[-lib]"
// #define TOKEN3_DESC "可选指令，含义为指定查找的库。默认查找4、6级库"
// #define TOKEN4 "[-1234]"
// #define TOKEN4_DESC "可选指令，含义为显示匹配的内容，1代表单词序号，2代表单词，3代表音标，4代表释义，0不显示。默认显示单词，释义"
// void find_help();
// #endif


#ifndef _EG_FIND_HELP_H
#define _EG_FIND_HELP_H

#include "../display/eg_print_help.h"

#define TOKEN1 "find"
#define TOKEN1_DESC "Required command, can be abbreviated as 'f'"

#define TOKEN2 "[%]word[%]"
#define TOKEN2_DESC "Required parameter: %% are optional. 'word' for exact match, 'word%%' for prefix match, '%%word' for suffix match, '%%word%%' for substring match"

#define TOKEN3 "[-lib]"
#define TOKEN3_DESC "Optional parameter: Specify dictionary library (default: CET4/CET6)"

#define TOKEN4 "[-1234]"
#define TOKEN4_DESC "Optional parameter: Select display fields (1=word index, 2=word, 3=phonetic, 4=definition, 0=none). Default: 2,4"

void find_help();

#endif