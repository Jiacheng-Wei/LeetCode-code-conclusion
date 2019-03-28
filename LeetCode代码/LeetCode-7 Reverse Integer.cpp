#include <stdlib.h>
#include <math.h>
#include <stdio.h>
 
int reverse(int x) {
	int rev=0;
	do{
		int pop=x%10;
		x/=10;
		if (rev>INT_MAX/10||(rev==INT_MAX/10&&pop>7)) return 0;
		if (rev<INT_MIN/10||(rev==INT_MIN/10&&pop<-8)) return 0;
		rev=rev*10+pop;
	}while(x!=0); 
    return rev;
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",reverse(x));
	return 0;
}
