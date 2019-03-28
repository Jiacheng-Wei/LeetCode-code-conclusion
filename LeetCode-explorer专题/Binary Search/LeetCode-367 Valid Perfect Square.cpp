/*
通过不断的对num除以2获得更小的数，知道找到那一个平方小于num的值，然后对其与其二倍数之间的每个数进行判断，如果存在一个数的平方
等于num则返回true否则返回false
例如：
一个数字49，我们先对其除以2，得到24，发现24的平方大于49，那么再对24除以2，得到12，发现12的平方还是大于49，再对12除以2，得到6，
发现6的平方小于49，于是遍历6到12中的所有数，看有没有平方等于49的，有就返回true，没有就返回false，参见代码如下： 
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
        for(long i=x;i<=2*x;i++)//这里i的格式一定要是long只有这样才不会出现超界的情况 
        {
            if(i*i==num) return true;
        }
        return false;
    }
};
/*
下面这种方法也比较高效，从1搜索到sqrt(num)，看有没有平方正好等于num的数
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
//二分法解决问题
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
下面这种方法就是纯数学解法了，利用到了这样一条性质，完全平方数是一系列奇数之和，例如：

1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
36 = 1 + 3 + 5 + 7 + 9 + 11
....
1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n

这里就不做证明了，我也不会证明，知道了这条性质，就可以利用其来解题了，时间复杂度为O(sqrt(n))。
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
//与第一种方法类似，但是代码量更简单了，注意这里面应用了数学方法 
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
