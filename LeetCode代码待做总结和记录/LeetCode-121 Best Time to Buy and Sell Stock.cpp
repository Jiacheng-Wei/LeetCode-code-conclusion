//brute force暴力算法，实现的时间复杂度是O(n^2)，所以很荣幸的是，时间爆了 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        for (int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                maxi=max(maxi,prices[j]-prices[i]);
            }
        }
        return maxi;
    }
};
//时间复杂度为O(n)的算法
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
}; 
