//�ݹ鷽������û�н�λʱ��Ҳ���ǵ�carry==0ʱ���ݹ������ʼ���� 
class Solution {
public:
    int getSum(int a, int b) {
       if (b==0) return a;
        int sum=a^b;
        int carry=(a&b)<<1;
        return getSum(sum,carry);
    }
};

//�򻯳���
class Solution {
public:
    int getSum(int a, int b) {
       return b==0 ? a:getSum(a^b,(a&b)<<1);
    }
};
//�����õݹ黹�����õ���ʵ��
class Solution {
public:
    int getSum(int a, int b) {
        while (b)
        {
            int carry=(a&b)<<1;//�ر�ע���ý�λ�ķ��� 
            a=a^b;//�ر�ע��ӵķ��� 
            b=carry;
        }
        return a;
    }
}; 

