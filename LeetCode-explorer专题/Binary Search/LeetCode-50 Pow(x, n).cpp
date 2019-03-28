/*
这道题让我们求x的n次方，如果我们只是简单的用个for循环让x乘以自己n次的话，未免也把LeetCode上的题想的太简单了，一句话形容图样图森破啊。
OJ因超时无法通过，所以我们需要优化我们的算法，使其在更有效的算出结果来。我们可以用递归来折半计算，每次把n缩小一半，这样n最终会缩小到0，
任何数的0次方都为1，这时候我们再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。还
有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可，代码如下：
*/ 
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1/power(x,-n);//该方法有一个问题在在于对于-2^31的n值，其负数超出了int的表示范围，所以在该测试用例的时候会出错 
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
关于第35行对于n为负情况的处理，可以通过举例的形式完成： 
看个简单的例子吧，myPow(2, -1)
那么half = myPow(2, -1/2)，其中-1/2=0, 那么half得到的值为1.
再往下走，不能整除2，且-1为负，所以就走到最后一个else了
return half * half / x，
因为指数是负数，所以要2变成分母，就是除以2了，得到二分之一这个结果。
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
这道题还有迭代的解法，我们让i初始化为n，然后看i是否是2的倍数，是的话x乘以自己，否则res乘以x，i每次循环缩小一半，直到为0停止循环。最后看n的
正负，如果为负，返回其倒数，参见代码如下：
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
 
