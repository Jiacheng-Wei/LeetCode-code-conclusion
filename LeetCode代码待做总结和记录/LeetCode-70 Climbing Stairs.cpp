//�����ַ:https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/2377/ 
//brute forceǿ�еݹ�Ľ��������⣬����ֳ�ʱ������Ҫ��dp������Ҳ�����ݹ�ⷨ��ʱ�临�Ӷ�ΪO(2^n)������ע����ĵݹ��dfs��ȫ�����еݹ�Ĳ�ͬ
//bottom-up�ķ��� 
class Solution {
public:
    int climbStairs(int n) {
        return generate(0,n);
    }
    int generate(int i,int n)
    {
        if (i>n) 
        {
            return 0;
        }
        if(i==n)
        {
            return 1;
        }
        return generate(i+1,n)+generate(i+2,n);
    }
}; 
//up-down�ķ�����
class Solution {
public:
    int climbStairs(int n) {
        int res=0;
        climb(res,n,1);
        climb(res,n,2);
        return res;
    }
    void climb(int& res,int n,int step)
    {
        if(n<=0) return;
        if(n-step==0)
        {
            res++;
            return;
        }
        climb(res,n-step,1);
        climb(res,n-step,2);
    }
}; 
//�ݹ���������洢��ÿһ���Ĳ������൱����һ����֦�Ĺ��̣�ʱ�临�Ӷ�ΪO(n) 
class Solution {
public:
    int climbStairs(int n) {
        int memo[n+1];
        return generate(0,n,memo);
    }
    int generate(int i,int n,int memo[])
    {
        if (i>n) 
        {
            return 0;
        }
        if(i==n)
        {
            return 1;
        }
        if(memo[i]>0)
        {
            return memo[i];
        }
        memo[i]=generate(i+1,n,memo)+generate(i+2,n,memo);
        return memo[i];
    }
}; 
//dp������⣬��Ҫ�ؿ���⣬�ֽ�ɶ��С���⣬������ֱ��������յĴ𰸣�ʱ�临�Ӷ�ΪO(n) 
/*
As we can see this problem can be broken into subproblems, and it contains the optimal substructure property i.e. its 
optimal solution can be constructed efficiently from optimal solutions of its subproblems, we can use dynamic programming to solve this problem.
One can reach i^{th} step in one of the two ways:
Taking a single step from (i-1)^{th} stepTaking a step of 22 from (i-2)^{th} step
So, the total number of ways to reach i^{th} is equal to sum of ways of reaching (i-1)^{th}step and ways of reaching (i-2)^{th}step.
Let dp[i]denotes the number of ways to reach on i^{th}step:
dp[i]=dp[i-1]+dp[i-2]
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
        {
            return 1;
        }
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        for (int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}; 
/*쳲��������У�In the above approach we have used dpdp array where dp[i]=dp[i-1]+dp[i-2] 
It can be easily analysed that dp[i]dp[i] is nothing but i^th fibonacci number. Fib(n)=Fib(n-1)+Fib(n-2)
Now we just have to find n^th number of the fibonacci series having 11 and 22 their first and second term respectively, i.e. 
Fib(1)=1 and Fib(2)=2. */ 
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
        {
            return 1;
        }
        int first=1;
        int second=2;
        for (int i=3;i<=n;i++)
        {
            int third=first+second;
            first=second;
            second=third;
        }
        return second;
    }
};
//ʱ�临�Ӷ�ΪO(n) 
 
 
