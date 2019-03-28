/*
�������������x��n�η����������ֻ�Ǽ򵥵��ø�forѭ����x�����Լ�n�εĻ���δ��Ҳ��LeetCode�ϵ������̫���ˣ�һ�仰����ͼ��ͼɭ�ư���
OJ��ʱ�޷�ͨ��������������Ҫ�Ż����ǵ��㷨��ʹ���ڸ���Ч���������������ǿ����õݹ����۰���㣬ÿ�ΰ�n��Сһ�룬����n���ջ���С��0��
�κ�����0�η���Ϊ1����ʱ�����������سˣ������ʱn��ż����ֱ�Ӱ��ϴεݹ�õ���ֵ���ƽ�����ؼ��ɣ����������������Ҫ���ϸ�x��ֵ����
��һ����Ҫ�������ǵ�ע�����n�п���Ϊ����������n�Ǹ�������������ǿ������������ֵ�����һ�������ȡ�䵹�����ɣ��������£�
*/ 
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1/power(x,-n);//�÷�����һ�����������ڶ���-2^31��nֵ���为��������int�ı�ʾ��Χ�������ڸò���������ʱ������ 
        return power(x,n);
    }
    double power(double x,int n){
        if(n==0) return 1;
        double half=power(x,n/2);
        if(n%2==0) return half*half;
        return x*half*half;
    }
};
/*
���ڵ�35�ж���nΪ������Ĵ�������ͨ����������ʽ��ɣ� 
�����򵥵����Ӱɣ�myPow(2, -1)
��ôhalf = myPow(2, -1/2)������-1/2=0, ��ôhalf�õ���ֵΪ1.
�������ߣ���������2����-1Ϊ�������Ծ��ߵ����һ��else��
return half * half / x��
��Ϊָ���Ǹ���������Ҫ2��ɷ�ĸ�����ǳ���2�ˣ��õ�����֮һ��������
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double half=myPow(x,n/2);
        if (n%2==0) return half*half;
        if(n>0) return x*half*half;
        return half*half/x;
    }
};
/*
����⻹�е����Ľⷨ��������i��ʼ��Ϊn��Ȼ��i�Ƿ���2�ı������ǵĻ�x�����Լ�������res����x��iÿ��ѭ����Сһ�룬ֱ��Ϊ0ֹͣѭ�������n��
���������Ϊ���������䵹�����μ��������£�
*/ 
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
 
