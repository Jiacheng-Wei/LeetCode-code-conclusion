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
//数学问题，牛顿迭代法求解。另一种方法是二分法 

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
//二分法的效率远低于牛顿迭代法的效率，二分法在LeetCode上运行要超时 
//这里给出一个博客有对两个方法的详细比较：https://blog.csdn.net/qq_26499321/article/details/73724763   
//https://blog.csdn.net/xusiwei1236/article/details/25657611 
int main()
{
	int x;
	cin>>x;
	Solution s;
	cout<<s.mySqrt(x);
	return 0;
}
