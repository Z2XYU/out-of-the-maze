#include "out of the maze.h"

int main()
{
    printf("欢迎进入逃出迷宫\n1.简单模式\n2.困难模式\n0.退出游戏\n");
    int choose=0;

    printf("请选择模式：");
    //将字符获取的字符转化为整形，减去字符'0',使其值为其值整形的大小
    choose=(int)getch()-'0';
    while (1)
    {
        switch (choose)
        {
        case EASY:
            easy();
            choose = Challenge();
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
