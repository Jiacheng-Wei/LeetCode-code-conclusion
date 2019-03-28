#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Firstpage();


int main()
{
	Firstpage();
	//循环检测是否开始游戏 
	char chInput;
	while (1)
	{
		chInput = _getch();
		if (' '==chInput)
		{
			break;
		}
	 } 
	 //进入游戏界面
	 system("cls");//清空控制台的函数 
	 printf("\t\t\t\tstart\n");
	 return 0;
 } 
 
 
 void Firstpage()
{
	printf ("\t\t\t\t欢迎来到贪吃蛇游戏\n"); 
	printf("\t\t\t\t游戏操作上下左右键\n");
	printf("\t\t\t\t请按空格键开始游戏\n"); 
}
