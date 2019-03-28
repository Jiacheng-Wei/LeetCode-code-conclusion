//这个题的方法是，求去每一个元素之前的数的积和之后的数的积，然后两者相乘即可。
//然后这次又学到了vector定义和声明的新方法，就是第7行的方法，可以预先声明n个元素，并赋初值。 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n,1),b(n,1),res(n);
        for (int i=0;i<n-1;i++)
        {
            f[i+1]=f[i]*nums[i];
        }
        for (int i=n-1;i>0;i--)
        {
            b[i-1]=b[i]*nums[i];
        }
        for (int i=0;i<n;i++)
        {
            res[i]=f[i]*b[i];
        }
        return res;
    }
};
