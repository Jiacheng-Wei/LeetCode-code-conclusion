//brute force�����㷨��ʵ�ֵ�ʱ�临�Ӷ���O(n^2)�����Ժ����ҵ��ǣ�ʱ�䱬�� 
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
//ʱ�临�Ӷ�ΪO(n)���㷨
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
