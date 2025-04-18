#include "../../../include/shellText/include.h"

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

// 定义指令名称
const char *text_cmd = "指令";
const char *text_eg_cmd = "eg";
const char *text_help_cmd = "help";
const char *text_exit_cmd = "exit";
// const char *text_time_cmd = "time";
const char *text_clear_cmd = "clear";
const char *text_story_cmd = "story";
const char *text_author_cmd = "author";
const char *text_find_cmd = "find|f content";
const char *text_list_cmd = "list|ls chapter";
const char *text_page_cmd = "page|p page_num";

// 定义指令对应的说明
const char *text_description = "指令功能";
const char *text_eg_description = "查询单词";
const char *text_help_description = "查看指令";
const char *text_exit_description = "退出程序";
// const char *text_time_description = "动态时间";
const char *text_clear_description = "清空屏幕";
const char *text_story_description = "软件故事";
const char *text_author_description = "作者信息";
const char *text_find_description = "查找内容";
const char *text_list_description = "查找目录";
const char *text_page_description = "跳转页面";

void text_help()
{
    const char *text_cmds[] = {text_cmd, text_eg_cmd,text_help_cmd, text_exit_cmd, text_clear_cmd, text_author_cmd, text_story_cmd, text_list_cmd, text_find_cmd, text_page_cmd, NULL};
    const char *text_descriptions[] = {text_description, text_eg_description,text_help_description, text_exit_description,text_clear_description, text_author_description, text_story_description, text_list_description, text_find_description, text_page_description, NULL};
    const char **text_columns[] = {text_cmds, text_descriptions};
    text_print_help(text_columns, sizeof(text_columns) / sizeof(text_columns[0]));
}

// int main()
// {
//     help();
//     return 0;
// }