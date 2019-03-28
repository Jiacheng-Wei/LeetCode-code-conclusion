/*
ͨ�����ϵĶ�num����2��ø�С������֪���ҵ���һ��ƽ��С��num��ֵ��Ȼ��������������֮���ÿ���������жϣ��������һ������ƽ��
����num�򷵻�true���򷵻�false
���磺
һ������49�������ȶ������2���õ�24������24��ƽ������49����ô�ٶ�24����2���õ�12������12��ƽ�����Ǵ���49���ٶ�12����2���õ�6��
����6��ƽ��С��49�����Ǳ���6��12�е�������������û��ƽ������49�ģ��оͷ���true��û�оͷ���false���μ��������£� 
*/ 
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        long x= num/2,t=x*x;
        while(t>num)
        {
            x=x/2;
            t=x*x;
        }
        for(long i=x;i<=2*x;i++)//����i�ĸ�ʽһ��Ҫ��longֻ�������Ų�����ֳ������� 
        {
            if(i*i==num) return true;
        }
        return false;
    }
};
/*
�������ַ���Ҳ�Ƚϸ�Ч����1������sqrt(num)������û��ƽ�����õ���num����
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
}; 
//���ַ��������
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            else if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
/*
�������ַ������Ǵ���ѧ�ⷨ�ˣ����õ�������һ�����ʣ���ȫƽ������һϵ������֮�ͣ����磺

1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
36 = 1 + 3 + 5 + 7 + 9 + 11
....
1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n

����Ͳ���֤���ˣ���Ҳ����֤����֪�����������ʣ��Ϳ����������������ˣ�ʱ�临�Ӷ�ΪO(sqrt(n))��
*/ 
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
//���һ�ַ������ƣ����Ǵ����������ˣ�ע��������Ӧ������ѧ���� 
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
}; 
