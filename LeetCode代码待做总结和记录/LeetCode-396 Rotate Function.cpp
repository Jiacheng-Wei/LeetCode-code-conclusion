/*
�Լ��ķ���������������ܴ������»ᳬʱ 
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len=A.size();
        if(len==0) return 0;
        int mx=INT_MIN;
        for(int j=0;j<len;j++)
        {
            int temp=A[len-1];//��һ������������ת��ÿ������ѭ����תһ�� 
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
���������ѵ�˼·��������õĽⷨӦ�����ҹ��ɣ���������������Ǹ������϶���ʱ��ʱ�临�Ӷ�Ӧ����O(n^2)
�ҹ��ɣ��ȰѾ�������ֳ���ΪA,B,C,D����ô���ǿ��Եõ���
F(0) = 0A + 1B + 2C +3D
F(1) = 0D + 1A + 2B +3C
F(2) = 0C + 1D + 2A +3B
F(3) = 0B + 1C + 2D +3A
��ô������ͨ����ϸ�۲죬���ǿ��Եó�����Ĺ��ɣ�
sum = 1A + 1B + 1C + 1D
F(1) = F(0) + sum - 4D
F(2) = F(1) + sum - 4C
F(3) = F(2) + sum - 4B
��ô���Ǿ��ҵ�������, F(i) = F(i-1) + sum - n*A[n-i]������д���������£�
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
//ע��������������������Ϊlong���������������Ĳ������ݳ��� 
 
