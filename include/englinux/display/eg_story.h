// # ifndef _EG_STORY_H
// # define _EG_STORY_H
// # include "eg_color.h"
// // 宏定义如果内容较多，要在每行末尾添加反斜杠 \ 来实现换行，并且反斜杠后面不能有任何字符（包括空格）
// #define EG_STORY BOLD RED"《因对流层而生的单词查询软件》\n"RESET\
// "本单词查询软件是在做毕设(对流层教材索引系统)时，发现每次查询单词都要打开app，联网，慢而繁琐。\n于是自己将离线单词查询嵌入为教材索引系统的子系统，两系统间仅仅一个接口，便于独立开发。\n"\
// "目前本系统仅仅收录4、6级词库。后续会加入用户记忆化查询、判题系统，形成一个更加专业的单词查询软件。\n"\

// # endif

#ifndef _EG_STORY_H
#define _EG_STORY_H
#include "eg_color.h"

#define EG_STORY BOLD RED"A Word Query Software Born for the Troposphere\n"RESET\
"This word query software was developed during my graduation project (Troposphere Textbook Indexing System).\nI found it slow and cumbersome to open an app and go online every time I needed to look up a word.\nThus, I embedded an offline word query feature as a subsystem of the textbook indexing system, with only one interface between the two systems for independent development.\n"\
"Currently, the system only includes CET4 and CET6 vocabulary databases.\nIn the future, user memorization queries and a problem-solving system will be added to form a more professional word query software.\n"

#endif