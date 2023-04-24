#include "out of the maze.h"

char lowerCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

char getDirection()
{
    char ch;
    printf("请输入'w','s','a','d'控制人物的行走方向。\n");
    scanf("%c", &ch);

    setbuf(stdin, NULL); // 清空缓冲区实现连续输入。

    ch = lowerCase(ch);
    return ch;
}

int win(int startRow, int startCol, int endRow, int endCol)
{
    if (startRow == endRow && startCol == endCol)
    {
        printf("恭喜走出迷宫。\n");
        return 0;
    }
}

int Challenge()
{
    printf("是否进入困难关卡?\n请输入Y或N:");
    char challenge;
    setbuf(stdin, NULL);
    scanf("%c%*c", &challenge);
    if (challenge == 'y' || challenge == 'Y')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}