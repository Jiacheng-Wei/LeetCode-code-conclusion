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
/*题目：Given an integer n, return the number of trailing zeroes in n!
这里只用找n!中5的因子个数，有的解法是同时要判断2的因子个数，但是我觉得没必要因为，只要有5就必然有2，所以2可以忽略。
具体怎么找了，就是n/5就可以了，但是要注意，25,125，这种5的n次方数，所以就要用一个循环来分解，代码见上。 
*/ 
