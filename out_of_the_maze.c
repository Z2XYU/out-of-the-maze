#include "out of the maze.h"

int main()
{
    printf("��ӭ�����ӳ��Թ�\n1.��ģʽ\n2.����ģʽ\n0.�˳���Ϸ");
    int input;
    char choose;

    printf("��ѡ��ģʽ��");
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
            printf("��ϲ��ͨ������ģʽ,���ڴ����ѵĹؿ�����\n");
            Sleep(1000);
            exit(0);
            break;
        case EXIT:
            printf("�˳���Ϸ\n");
            Sleep(1000);
            exit(0);
        default:
            printf("ģʽ��δ���������ڴ�");
            break;
        }
    }
    return 0;
}
