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
//��ʱ���ٵ��㷨������û�н���������ת��ֻ����һ��ĵ�ת������������жϵ���һ���ˣ����ǵ�x>revʱִ��ѭ������x<revʱ��˵������һ����
//���x��λ����ż���Ļ�����ô����ͨ��x==rev�Ϳ����ж��Ƿ��ǻ��������������x��λ���������Ļ�����Ҫͨ��x==rev/10���ж��� 
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
