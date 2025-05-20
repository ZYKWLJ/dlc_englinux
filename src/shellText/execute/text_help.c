#include "../../../include/shellText/include.h"

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

// 定义指令名称
const char *text_cmd = "Command";
const char *text_eg_cmd = "eg|e";
const char *text_help_cmd = "help|h";
const char *text_exit_cmd = "quit|q";
const char *text_list_all_cmd = "list|ls";
// const char *text_time_cmd = "time";
const char *text_clear_cmd = "clear";
const char *text_story_cmd = "story";
const char *text_author_cmd = "author";
const char *text_subject_cmd = "subject";
const char *text_find_cmd = "find|f content";
const char *text_list_cmd = "list|ls chapter";
const char *text_page_cmd = "page|p page_num";

// // 定义指令对应的说明
// const char *text_description = "指令功能";
// const char *text_eg_description = "查询单词";
// const char *text_help_description = "查看指令";
// const char *text_exit_description = "退出程序";
// const char *text_list_all_description = "全部目录";
// // const char *text_time_description = "动态时间";
// const char *text_clear_description = "清空屏幕";
// const char *text_story_description = "软件故事";
// const char *text_author_description = "作者信息";
// const char *text_subject_description = "学科介绍";
// const char *text_find_description = "查找内容";
// const char *text_list_description = "详细目录";
// const char *text_page_description = "跳转页面";
// Define command descriptions
const char *text_description = "Command Function";
const char *text_eg_description = "Query Word";
const char *text_help_description = "View Help";
const char *text_exit_description = "Exit Program";
const char *text_list_all_description = "Show All Categories";
// const char *text_time_description = "Dynamic Time";
const char *text_clear_description = "Clear Screen";
const char *text_story_description = "Software Story";
const char *text_author_description = "Author Info";
const char *text_subject_description = "Subject Introduction";
const char *text_find_description = "Search Content";
const char *text_list_description = "Detailed Directory";
const char *text_page_description = "Jump to Page";
void text_help()
{
    const char *text_cmds[] = {text_cmd, text_eg_cmd, text_help_cmd, text_exit_cmd, text_list_all_cmd, text_clear_cmd, text_author_cmd, text_story_cmd, text_subject_cmd, text_list_cmd, text_find_cmd, text_page_cmd, NULL};
    const char *text_descriptions[] = {text_description, text_eg_description, text_help_description, text_exit_description, text_list_all_description, text_clear_description, text_author_description, text_story_description, text_subject_description, text_list_description, text_find_description, text_page_description, NULL};
    const char **text_columns[] = {text_cmds, text_descriptions};
    text_print_help(text_columns, sizeof(text_columns) / sizeof(text_columns[0]));
}

// int main()
// {
//     help();
//     return 0;
// }