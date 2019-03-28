//递归方法，当没有进位时，也就是当carry==0时，递归结束开始回溯 
class Solution {
public:
    int getSum(int a, int b) {
       if (b==0) return a;
        int sum=a^b;
        int carry=(a&b)<<1;
        return getSum(sum,carry);
    }
};

//简化程序
class Solution {
public:
    int getSum(int a, int b) {
       return b==0 ? a:getSum(a^b,(a&b)<<1);
    }
};
//除了用递归还可以用迭代实现
class Solution {
public:
    int getSum(int a, int b) {
        while (b)
        {
            int carry=(a&b)<<1;//特别注意获得进位的方法 
            a=a^b;//特别注意加的方法 
            b=carry;
        }
        return a;
    }
}; 

