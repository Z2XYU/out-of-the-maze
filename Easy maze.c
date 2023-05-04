#include "out of the maze.h"

int EstartROW = 1;
int EstartCol = 1;
int EendROW = 2;
int EendCol = 5;

void PrintEmap(char Emap[6][6], int row, int col)
{
    system("cls");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", Emap[i][j]);
        }
        printf("\n");
    }
}

void Emove(char choose, char Emap[6][6])
{
    switch (choose)
    {
    case 'w':
        {
            Emap[EstartROW][EstartCol] = ' ';
            Emap[EstartROW - 1][EstartCol] = 'R';

            EstartROW = EstartROW - 1;
        }
        break;
    case 's':
        if (Emap[EstartROW + 1][EstartCol] != '#' && EstartROW >= 0 && EstartCol >= 0)
        {
            Emap[EstartROW][EstartCol] = ' ';
            Emap[EstartROW + 1][EstartCol] = 'R';
            EstartROW = EstartROW + 1;
        }
        break;
    case 'a':
        if (Emap[EstartROW][EstartCol - 1] != '#' && EstartROW >= 0 && EstartCol >= 0)
        {
            Emap[EstartROW][EstartCol] = ' ';
            Emap[EstartROW][EstartCol - 1] = 'R';

            EstartCol = EstartCol - 1;
        }
        break;
    case 'd':
        if (Emap[EstartROW][EstartCol + 1] != '#' && EstartROW >= 0 && EstartCol >= 0)
        {
            Emap[EstartROW][EstartCol] = ' ';
            Emap[EstartROW][EstartCol + 1] = 'R';

            EstartCol = EstartCol + 1;
        }
        break;
    default:
        printf("没有该方向。\n");
        Sleep(1000);
        break;
    }
}

void easy()
{
    system("cls");
    char Emap[6][6] = {{'#', '#', '#', '#', '#', '#'},
                       {'#', 'R', ' ', '#', ' ', '#'},
                       {'#', ' ', '#', '#', ' ', ' '},
                       {'#', ' ', ' ', '#', ' ', '#'},
                       {'#', '#', ' ', ' ', ' ', '#'},
                       {'#', '#', '#', '#', '#', '#'}};
    int row = sizeof(Emap) / sizeof(Emap[1]);
    int col = sizeof(Emap[1]) / sizeof(Emap[1][1]);
    PrintEmap(Emap, row, col);
    while (1)
    {
        char choose = getDirection();
        Emove(choose, Emap);
        PrintEmap(Emap, row, col);

        if (win(EstartROW, EstartCol, EendROW, EendCol))
            break;
    }
}
