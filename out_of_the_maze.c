#include "out of the maze.h"

int main()
{
    printf("欢迎进入逃出迷宫\n1.简单模式\n2.困难模式\n0.退出游戏");
    int input;
    char choose;

    printf("请选择模式：");
    scanf("%d%*c", &input);
    while (1)
    {
        switch (input)
        {
        case EASY:
            easy();
            input = Challenge();
            break;
        case DIFFICULT:
            difficult();
            printf("恭喜你通过困难模式,请期待更难的关卡更新\n");
            Sleep(1000);
            exit(0);
            break;
        case EXIT:
            printf("退出游戏\n");
            Sleep(1000);
            exit(0);
        default:
            printf("模式还未开发尽请期待");
            break;
        }
    }
    return 0;
}
