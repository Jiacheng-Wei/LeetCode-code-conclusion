/*时间复杂度为O(n)，这道题的思路是，首先把所有的数据转化到图像上面，就会发现要有利润就要发现山谷和沟壑，当然是类比了，目标是发现找到所有的沟壑和 
寻找一个沟壑在出现下一个沟壑时的最高的山峰，两个相减就是该沟壑产生的最大利润了，所有利润相加即是总利润。 
*/ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int i=0;
        int valley=prices[0];
        int peak=prices[0];
        int maxpr=0;
        while(i<prices.size()-1)
        {
            while(i<prices.size()-1&&prices[i]>=prices[i+1]) i++;
            valley=prices[i];
            while(i<prices.size()-1&&prices[i]<=prices[i+1]) i++;
            peak=prices[i];
            maxpr+=peak-valley;
        }
        return maxpr;
    }
};
/*
另一个方法是就是线性方法，就是遇到一个沟壑就和相邻的数一直减，知道遇见下一个沟壑，这样也是能出最大的结果的，时间复杂度O(n)； 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1]) maxpro+=prices[i]-prices[i-1];
        }
        return maxpro;
    }
};
