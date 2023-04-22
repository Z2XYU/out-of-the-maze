#include<stdio.h>
#include<string.h>
#include<stdlib.h>                                  
char lowerCase(char ch);
void printMap(char map[13][17],int row,int col);
char getDirection();
void move(char ch,char map[13][17]);
int startRow=1;
int startCol=0;

int endRow=1;
int endCol=16;

int main()
{
    
    char map[13][17]={
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'R',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' '},
{'#',' ','#',' ','#','#','#','#','#',' ','#','#','#',' ','#','#','#'},
{'#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
{'#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#'},
{'#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' '},
{'#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#',' ','#'},
{'#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ','#','#',' ','#',' ','#',' ','#','#','#','#','#'},
{'#',' ','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' '},
{'#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'}};
    

    int row=sizeof(map)/sizeof(map[1]);                 
    int col=sizeof(map[1]);                              
    printMap(map,row,col);                                   


    do{
        char ch=getDirection();                              

        move(ch,map);                                        

        printMap(map,row,col);                               

        if(startRow == endRow && startCol == endCol)         
        {
            printf("恭喜走出迷宫。\n");
            break;
        }
    }while(1);                                               
    return 0;
}


void printMap(char map[13][17],int row,int col)
{
    system("cls");      //清空屏幕   system头文件#include<stdlib.h>                             

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

char lowerCase(char ch)
{
    if(ch >= 'A'&&ch <= 'Z')            
    {
        return ch+('a'-'A');            
    }
    return ch;                          
}

char getDirection()                  
{
    char ch;
    printf("请输入'w','s','a','d'控制人物的行走方向。\n");
    scanf("%c",&ch);                 

    setbuf(stdin,NULL);     //清空缓冲区实现连续输入。             

    ch=lowerCase(ch);                
    return ch;                      
}

void move(char ch,char map[13][17])
{
    switch (ch)                                   
    {
    case 'w':
        if(map[startRow-1][startCol] != '#')     
        {
           map[startRow][startCol] = ' ';
           map[startRow - 1][startCol] = 'R';

           
           startRow = startRow - 1;
           startCol = startCol;

        }
        break;
    case 's':
         if(map[startRow + 1][startCol] != '#')
        {
           map[startRow][startCol] = ' ';
           map[startRow + 1][startCol] = 'R';
           startRow = startRow + 1;
           startCol = startCol;
        }
        break;
    case 'a':
         if(map[startRow][startCol - 1] != '#')
        {
           map[startRow][startCol] = ' ';
           map[startRow][startCol - 1] = 'R';
           startRow = startRow;
           startCol = startCol - 1;
        }
        break;
    case 'd':
         if(map[startRow][startCol + 1] != '#')
        {
           map[startRow][startCol] = ' ';
           map[startRow][startCol +1] = 'R';
           startRow = startRow;
           startCol = startCol + 1;
        }
        break;
    default:
        printf("没有该方向。\n");           
        break;
    }
}