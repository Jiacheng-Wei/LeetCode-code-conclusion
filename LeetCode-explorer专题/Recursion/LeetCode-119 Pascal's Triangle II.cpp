/*
�ο�����:https://www.cnblogs.com/grandyang/p/4031536.html 
��������ε�n�㣨����Ƶ�0�㣬��1�У���n�㼴��n+1�У��˴�nΪ����0���ڵ���Ȼ�������ö�Ӧ�ڶ���ʽ\left(a+b\right)^{n}չ����ϵ����
����ڶ���1 2 1����ָ��Ϊ2�Ķ���ʽ\left(a+b\right)^{2}չ����ʽa^{2}+2ab+b^{2}��ϵ����
���������Ҫ�������������ʣ�
������������������ɣ��������ҶԳƣ�ÿ����1��ʼ�𽥱��Ȼ���С���ص�1��
��n�е����ָ���Ϊn����
��n�еĵ�k������Ϊ�����C_{n-1}^{k-1}��
��n�����ֺ�Ϊ2^{n-1}��
��ÿ������������Ҳ���������⣬ÿ�����ֵ����������Ϸ������Ϸ���������֮�ͣ�Ҳ����˵����n�е�k�����ֵ��ڵ�n-1�еĵ�k-1���������k�����ֵĺͣ���
������Ϊ����Ϻ��ʽ��C_{n}^{i}=C_{n-1}^{i-1}+C_{n-1}^{i}�����ô�����д��������������Ρ�
 

������Ŀ�ж�����������������ֻ��ʹ��O(k)�Ķ���ռ䣬��ô�����Ͳ��ܰ�ÿ�ж������������Ҫ�������ķ���, �����ȿ����õ��ǵ��������ʣ�
���ÿ������������ɵ�n��ϵ�����ص������ǰʮ�У�ûɶ���⣬�õ�OJ�ϲ��ԣ������ڵ�18�й��ˣ��м��и�ϵ������ȷ����ô������������أ�
��ϸ���ң�ԭ�����ڼ����������������������ʱ��Ҫ�����ˣ���������int����ֵ��Χֻ��-32768��32768֮�䣬��ôһ��nֵ�������˿϶�
�޷����㡣��ɥ�Ĳ����OJ�϶�����Ե��ɰ���ǧ�У���������������С�
*/ 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out;
        if (rowIndex < 0) return out;
        for (int i = 0; i <= rowIndex; ++i) {
            if ( i == 0 || i == rowIndex) out.push_back(1);
            else out.push_back (computeCnk(rowIndex, i));
        }
        return out;
    }
     
    int computeCnk(int n, int k) {
        if (k > n) return 0;
        if (k > n/2) k = n - k;
        int numerator = 1, denominator = 1;
        for (int i = 0; i < k; ++i) {
            numerator *= n - i;
            denominator *= k - i;
        }
        if (denominator != 0) return numerator/denominator;
        return 0;
    }
};
/*
��ô���������������õ��������ʣ����˵�һ�������һ������֮�⣬���������ֶ�����һ����������ֵ֮�͡���ô����ֻ��Ҫ����forѭ����
���˵�һ����Ϊ1֮�⣬�������������һ��ѭ������ֵ������ǰ��λ�õ���ֵ֮�ͣ���ͣ�ظ���ÿһ��λ�õ�ֵ������Եõ���n�е����֣�
����ʵ�ִ������£�
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
//�Լ��ķ������������˼����һ���ģ��ռ临�Ӷ�����Ҫ�󣬵���ʱ�临�Ӷȳ��ˣ�����oj������
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex<0) return res;
        for(int i=0;i<=rowIndex;i++)
        {
            res.push_back(recur(rowIndex,i));
        }
        return res;
        
    }
    int recur(int row, int column)
    {
        if(row<0||column>row) return 0;
        else if(column==row||column==0) return 1;
        else return recur(row-1,column)+recur(row-1,column-1);
    }
}; 

