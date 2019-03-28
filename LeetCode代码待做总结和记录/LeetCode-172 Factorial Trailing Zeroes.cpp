class Solution {
public:
    int trailingZeroes(int n) {
        int num=0;
        while (n)
        {
            num+=n/5;
            n/=5;
        }
        return num;
    }
};
/*��Ŀ��Given an integer n, return the number of trailing zeroes in n!
����ֻ����n!��5�����Ӹ������еĽⷨ��ͬʱҪ�ж�2�����Ӹ����������Ҿ���û��Ҫ��Ϊ��ֻҪ��5�ͱ�Ȼ��2������2���Ժ��ԡ�
������ô���ˣ�����n/5�Ϳ����ˣ�����Ҫע�⣬25,125������5��n�η��������Ծ�Ҫ��һ��ѭ�����ֽ⣬������ϡ� 
*/ 
