#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define EXIT 0
#define EASY 1
#define DIFFICULT 2

char getDirection();
char lowerCase(char ch);
int win(int startRow, int startCol, int endRow, int endCol);
int Challenge();

// 困难模式
void difficult();

void printDMap(char Dmap[13][17], int row, int col);

void move(char ch, char Dmap[13][17]);

// 简单模式
void easy();

void PrintEmap(char Emap[6][6], int row, int col);

void Emove(char choose, char Emap[6][6]);