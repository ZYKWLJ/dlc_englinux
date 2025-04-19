#include "../../../include/englinux/execute/eg_help.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

// 定义指令名称
const char *cmd = "指令";

const char *help_cmd = "help|h";
const char *back_cmd = "back|b";
const char *exit_cmd = "quit|q";
const char *clear_cmd = "clear";
const char *total_cmd = "total";
const char *author_cmd = "author";
const char *story_cmd = "story";

const char *find_cmd = "find|f word";

// 定义指令对应的说明
const char *description = "指令功能";
const char *help_description = "查看指令表";
const char *back_description = "返回对流层";
const char *exit_description = "退出程序";
const char *clear_description = "清空屏幕";
const char *total_description = "单词总数";
const char *author_description = "作者信息";
const char *story_description = "软件故事";

const char *find_description = "搜索单词";

void eg_help()
{
    const char *cmds[] = {cmd, help_cmd,back_cmd, exit_cmd, clear_cmd, total_cmd,  author_cmd, story_cmd,find_cmd, NULL};
    const char *descriptions[] = {description, help_description,back_description, exit_description, clear_description, total_description, 
    author_description,  story_description, find_description, NULL};
    const char **columns[] = {cmds, descriptions};
    eg_print_help(columns, sizeof(columns) / sizeof(columns[0]));
}


// int main()
// {
//     help();
//     return 0;
// }