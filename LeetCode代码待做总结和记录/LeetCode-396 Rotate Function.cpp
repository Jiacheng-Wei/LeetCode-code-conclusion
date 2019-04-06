/*
自己的方法，最终在数组很大的情况下会超时 
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len=A.size();
        if(len==0) return 0;
        int mx=INT_MIN;
        for(int j=0;j<len;j++)
        {
            int temp=A[len-1];//这一部分是数组轮转，每进几次循环轮转一次 
            for(int i=0;i<len;i++){
                int t=A[i];
                A[i]=temp;
                temp=t;
            }
            int t=0;
            for(int k=0;k<len;k++)
            {
                t+=A[k]*k;
            }
            mx=max(t,mx);
        }
        return mx;
    }
};
/*
看了下网友的思路，这题最好的解法应该是找规律，否则用我上面的那个方法肯定超时，时间复杂度应该是O(n^2)
找规律，先把具体的数字抽象为A,B,C,D，那么我们可以得到：
F(0) = 0A + 1B + 2C +3D
F(1) = 0D + 1A + 2B +3C
F(2) = 0C + 1D + 2A +3B
F(3) = 0B + 1C + 2D +3A
那么，我们通过仔细观察，我们可以得出下面的规律：
sum = 1A + 1B + 1C + 1D
F(1) = F(0) + sum - 4D
F(2) = F(1) + sum - 4C
F(3) = F(2) + sum - 4B
那么我们就找到规律了, F(i) = F(i-1) + sum - n*A[n-i]，可以写出代码如下：
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long t = 0, sum = 0;
        long n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            t += i * A[i];
        }
        long res = t;
        for (int i = 1; i < n; ++i) {
            t = t + sum - n * A[n - i];
            res = max(res, t);
        }
        return (int)res;
    }
};
//注意这道题的所有数的类型为long，否则会在最后计组的测试数据超界 
 
