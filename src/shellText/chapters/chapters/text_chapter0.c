#include "../../../../include/shellText/include.h"
void display_chapter0()
{
    // setlocale(LC_ALL, "");      // 设置本地化，支持宽字符
    SET_CHINESE_LOCALE();

    system("chcp 65001 > nul"); // 隐藏命令输出

    CHAPTER_1("绪论", 1);
    CHAPTER_2("晴空大气的物理及电磁特性", 12);
    CHAPTER_3("大气沉降粒子物理及电磁特性", 91);
    CHAPTER_4("对流层顶及其气候特征", 201);
    CHAPTER_5("晴空大气中的传播与散射", 206);
    CHAPTER_6("大气沉降粒子中的传播与散射", 255);
    CHAPTER_7("对流层大气中的光传输特性简介", 353);
    CHAPTER_8("对流层环境对无线系统的影响", 369);
    CHAPTER_9("对流层中传输特性测量及模型分析", 421);
}