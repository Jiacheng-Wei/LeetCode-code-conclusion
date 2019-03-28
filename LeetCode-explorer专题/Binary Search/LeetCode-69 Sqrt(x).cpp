#include <stdio.h>
#include <iostream>
using namespace std;

/*class Solution {
public:
    int mySqrt(int x) {
  		if(x == 0) return 0;
  		double last  = 0;
  		double res = 1;
  		while( res != last ) {
  			last = res;
  			res = (res + x / res) / 2;
  		}      
  		return int(res);
    }
};*/ 
//��ѧ���⣬ţ�ٵ�������⡣��һ�ַ����Ƕ��ַ� 

class Solution {
public:
    int mySqrt(int x) {
        double left=0,right=x;
        double mid,last;
        mid=left+(right-left)/2;
        do
        {
            if(mid*mid==x) last=mid;
            if (mid*mid>x)
            {
                last=mid;
                right=mid;
            }
            else if(mid*mid<x)
            {
                last=mid;
                left=mid;
            }
            mid=left+(right-left)/2;
        }while (last!=mid);
        return int(mid);
        
    }
};
//���ַ���Ч��Զ����ţ�ٵ�������Ч�ʣ����ַ���LeetCode������Ҫ��ʱ 
//�������һ�������ж�������������ϸ�Ƚϣ�https://blog.csdn.net/qq_26499321/article/details/73724763   
//https://blog.csdn.net/xusiwei1236/article/details/25657611 
int main()
{
	int x;
	cin>>x;
	Solution s;
	cout<<s.mySqrt(x);
	return 0;
}
