#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Firstpage();


int main()
{
	Firstpage();
	//ѭ������Ƿ�ʼ��Ϸ 
	char chInput;
	while (1)
	{
		chInput = _getch();
		if (' '==chInput)
		{
			break;
		}
	 } 
	 //������Ϸ����
	 system("cls");//��տ���̨�ĺ��� 
	 printf("\t\t\t\tstart\n");
	 return 0;
 } 
 
 
 void Firstpage()
{
	printf ("\t\t\t\t��ӭ����̰������Ϸ\n"); 
	printf("\t\t\t\t��Ϸ�����������Ҽ�\n");
	printf("\t\t\t\t�밴�ո����ʼ��Ϸ\n"); 
}
