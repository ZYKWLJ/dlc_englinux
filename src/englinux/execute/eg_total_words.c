#include "../../../include/englinux/execute/eg_total_words.h"
extern word_entry **library[LIB_NUM];
void eg_total_words()
{
    int total = 0;
    for (int i = 0; i < LIB_NUM - 1; i++) // 单个词库
    {
        int count = 0;
        for (int j = 0; j < 25; j++) // 词库单个开头字母单词
        {
            for (int k = 0; library[i][j][k].word; k++) // 词库单个开头字母单词的单个单词
            {

                count++;
            }
        }
        total += count;
        printf("收录%d级词库单词数：%s%s%d%s\n", i == 0 ? 4 : 6, RED,BOLD,count,RESET);
    }
    printf("收录总单词数：%s%s%d%s\n", RED,BOLD,total,RESET);
}
