//LeetCode-9
#include <stdio.h>
bool isPalindrome(int x) {
        int y,rev=0;
        if (x<0) return false;
        else{
            y=x;
            do{
                int pop=x%10;
                x/=10;
                rev=rev*10+pop;
            }while(x!=0);
            if (rev==y) return true;
            else return false;
        }
    }
int main()
{
	int x;
	scanf("%d",&x);
	if (isPalindrome(x)) printf("true");
	else printf("false");
}

/*
//耗时更少的算法，它并没有将整个数倒转，只求了一半的倒转数。但是如何判断到了一半了，就是当x>rev时执行循环，当x<rev时，说明超过一半了
//如果x的位数是偶数的话，那么可以通过x==rev就可以判断是否是回文数，但是如果x的位数是奇数的话，就要通过x==rev/10来判断了 
class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0;
        if (x<0||x%10==0&&x!=0) return false;
        else{
            do{
                int pop=x%10;
                x/=10;
                rev=rev*10+pop;
            }while(x>rev);
            return x==rev||x==rev/10;
        }
    }
};
*/ 
