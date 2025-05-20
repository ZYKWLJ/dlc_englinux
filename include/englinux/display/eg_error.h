// # ifndef _EG_ERROR_H
// # define _EG_ERROR_H
// #define EG_ERROR_FIND_F_ONLY_ONE_ARGUMENT "%s%s命令不全，find|f 后需加查询单词%s\n"
// #define EG_ERROR_FOR_HELP "(输入%s%shelp%s获取帮助)\n"
// #define EG_ERROR_CMDS "%s%s%s--无效指令!%s(输入%s%shelp%s获取帮助)\n"
// #define EG_ERROR_LIB_NOT_EXIST "%s%s词库%d--尚未录入!%s目前仅支持4、6级库\n"
// #endif

#ifndef _EG_ERROR_H
#define _EG_ERROR_H

#define EG_ERROR_FIND_F_ONLY_ONE_ARGUMENT "%s%sIncomplete command: find|f requires a search term%s\n"
#define EG_ERROR_FOR_HELP "(Type %s%shelp%s for help)\n"
#define EG_ERROR_CMDS "%s%s%s--Invalid command!%s (Type %s%shelp%s for help)\n"
#define EG_ERROR_LIB_NOT_EXIST "%s%sDictionary %d--Not available!%s Only CET4/CET6 libraries are supported currently\n"

#endif