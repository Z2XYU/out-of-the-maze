#include "out of the maze.h"

int main()
{
    printf("��ӭ�����ӳ��Թ�\n1.��ģʽ\n2.����ģʽ\n0.�˳���Ϸ\n");
    int choose=0;

    printf("��ѡ��ģʽ��");
    //���ַ���ȡ���ַ�ת��Ϊ���Σ���ȥ�ַ�'0',ʹ��ֵΪ��ֵ���εĴ�С
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
