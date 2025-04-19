#include "../../../include/shellText/include.h"

void text_execute_one_token(char *token[], int token_num, char *origin_str)
{
    if (strcmp(token[0], "help") == 0||strcmp(token[0], "h") == 0)
    {
        text_help();
        return;
    }
    else if (strcmp(token[0], "clear") == 0)
    {
        text_clear();
        return;
    }
    else if (strcmp(token[0], "quit") == 0||strcmp(token[0], "q") == 0)
    {
        text_exit_signal_handler(2);
    }
    else if (strcmp(token[0], "author") == 0)
    {
        author();
        return;
    }
    else if (strcmp(token[0], "story") == 0)
    {
        printf(STORY);
        return;
    }
    else if (strcmp(token[0], "subject") == 0)
    {
        printf(SUBJECT);
        return;
    }
    else if (strcmp(token[0], "eg") == 0||strcmp(token[0], "e") == 0)
    {
        englinux();
        return;
    }
    else if (strcmp(token[0], "list") == 0 || strcmp(token[0], "ls") == 0)
    {
        display_chapters(0);
        return;
    }
    // 单长度指令find、f需要单独判断！
    else if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
    {
        printf(ERROR_FIND_F_ONLY_ONE_ARGUMENT, BOLD, YELLOW, RESET);
        printf(ERROR_FOR_HELP, BOLD, YELLOW, RESET);
        return;
    }
    // 单长度指令page、p需要单独判断页数！
    else if (strcmp(token[0], "page") == 0 || strcmp(token[0], "p") == 0)
    {
        printf(ERROR_PAGE_P_ONLY_ONE_ARGUMENT, BOLD, YELLOW, RESET);
        return;
    }
    else
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        text_find_similar_commands(origin_str);
        return;
    }
}