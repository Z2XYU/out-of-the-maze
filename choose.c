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
    printf("������'w','s','a','d'������������߷���\n");
    scanf("%c", &ch);

    setbuf(stdin, NULL); // ��ջ�����ʵ���������롣

    ch = lowerCase(ch);
    return ch;
}

int win(int startRow, int startCol, int endRow, int endCol)
{
    if (startRow == endRow && startCol == endCol)
    {
        printf("��ϲ�߳��Թ���\n");
        return 0;
    }
}

int Challenge()
{
    printf("�Ƿ�������ѹؿ�?\n������Y��N:");
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