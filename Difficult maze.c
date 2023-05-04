#include "out of the maze.h"

int DstartRow = 1;
int DstartCol = 0;
int DendRow = 1;
int DendCol = 16;

void printDMap(char Dmap[13][17], int row, int col)
{
    system("cls"); // 清空屏幕   system头文件#include<stdlib.h>

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c", Dmap[i][j]);
        }
        printf("\n");
    }
}

void move(char ch, char Dmap[13][17])
{
    switch (ch)
    {
    case 'w':
        if (Dmap[DstartRow - 1][DstartCol] != '#' && DstartRow >= 0 && DstartCol >= 0)
        {
            Dmap[DstartRow][DstartCol] = ' ';
            Dmap[DstartRow - 1][DstartCol] = 'R';

            DstartRow = DstartRow - 1;
        }
        break;
    case 's':
        if (Dmap[DstartRow + 1][DstartCol] != '#' && DstartRow >= 0 && DstartCol >= 0)
        {
            Dmap[DstartRow][DstartCol] = ' ';
            Dmap[DstartRow + 1][DstartCol] = 'R';
            DstartRow = DstartRow + 1;
        }
        break;
    case 'a':
        if (Dmap[DstartRow][DstartCol - 1] != '#' && DstartRow >= 0 && DstartCol >= 0)
        {
            Dmap[DstartRow][DstartCol] = ' ';
            Dmap[DstartRow][DstartCol - 1] = 'R';

            DstartCol = DstartCol - 1;
        }
        break;
    case 'd':
        if (Dmap[DstartRow][DstartCol + 1] != '#' && DstartRow >= 0 && DstartCol >= 0)
        {
            Dmap[DstartRow][DstartCol] = ' ';
            Dmap[DstartRow][DstartCol + 1] = 'R';

            DstartCol = DstartCol + 1;
        }
        break;
    default:
        printf("没有该方向。\n");
        Sleep(1000);
        break;
    }
}

void difficult()
{
    char Dmap[13][17] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                         {'R', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
                         {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'},
                         {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
                         {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#'},
                         {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
                         {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
                         {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
                         {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#'},
                         {'#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' '},
                         {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#'},
                         {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
                         {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'}};
    int row = sizeof(Dmap) / sizeof(Dmap[1]);
    int col = sizeof(Dmap[1]);
    printDMap(Dmap, row, col);
    do
    {
        char ch = getDirection();

        move(ch, Dmap);

        printDMap(Dmap, row, col);

        if (win(DstartRow, DstartCol, DendRow, DendCol))
            break;
    } while (1);
}