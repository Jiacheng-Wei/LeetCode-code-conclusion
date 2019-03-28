#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
char ch[]={'I','V','X','L','C','D','M'};
int num[]={1,5,10,50,100,500,1000}; 
int hash(char c){
    int i=0;
    for (i;i<8;i++){
	    if (ch[i]==c){
        	return i;
        }
        else continue;
    }
    if (i==7) return 7;
}
int romanToInt(string s){
    int lenth;
    int sum=0;
    lenth=s.length();
    if (lenth==1)
    {
    	sum=sum+num[hash(s[0])];
	}
	else
	{
		for (int i=0;i<lenth-1;i++)
		{
			int front=hash(s[i]);
        	int back=hash(s[i+1]);
        	printf("%d %d\n",front,back);
        	if (front<back)
			{
           		sum=sum+num[back]-num[front];
            	i+=1;
        	}
       		else
			{
            	sum=sum+num[front];
        	}
   		}
   		if (hash(s[lenth-1])<=hash(s[lenth-2])) sum=sum+num[hash(s[lenth-1])];
	}
    return sum;
}

int main()
{
	char s[100];
	scanf("%s",s);
	printf("%d",romanToInt(s));
	return 0;
}
