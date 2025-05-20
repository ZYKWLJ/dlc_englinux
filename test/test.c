#include <stdio.h>
#include <stdlib.h>

int main() {
    // Windows 需设置控制台编码为 UTF-8
    system("chcp 65001 > nul"); // 隐藏命令输出
    printf("中文测试：对流层传播与散射\n");
    return 0;
}