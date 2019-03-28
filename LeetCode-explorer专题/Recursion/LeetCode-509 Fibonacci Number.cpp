//最简单的递归版本 
int fib(int N) {
    if (N <= 1) return N;
    return fib(N-1) + fib(N-2);
}
//斐波拉契数列的递归版memoization的解法，简单版的动态规划 
class Solution {
public:
    int fib(int N) {
        unordered_map<int,int> mp;
        int res=fibo(mp,N);
        return res;
    }
    int fibo(unordered_map<int,int>& map, int N)
    {
        if(map.count(N)!=0)
        {
            return map[N];
        }
        int res;
        if(N<2)
        {
            res=N;
        }
        else
        {
            res=fibo(map,N-1)+fibo(map,N-2);
        }
        map[N]=res;
        return res;
    }
};
//动态规划
int fib(int N)
{
    int *vec = new int[N+1];
    vec[0] = 0;
    vec[1] = 1;

    for(int i = 2; i <= N; i++)
    {
        vec[i] = vec[i-1] + vec[i-2];
    }

    return vec[N];
}
 
