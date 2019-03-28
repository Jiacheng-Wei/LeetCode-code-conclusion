class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        bool *p=new bool[n];
        memset(p,true,sizeof(bool)*n);
        for (int i=2;i*i<n;i++)
        {
                if(p[i])//为什么要判断p[i]，目的是减少循环次数，因为如果i本身就不是素数那么i*j也就不是素数 
                {
                    for(int j=2;j*i<n;j++)
                    {
                        p[i*j]=false;
                    }//这里类似一个hash表将每一个数的判断情况记录下来 
                }
        }
        int count=0;
        for (int i=2;i<n;i++)
        {
            if (p[i])
            {
                count++;
            }
        }
        
        return count;
    }
};
