/*ʱ�临�Ӷ�ΪO(n)��������˼·�ǣ����Ȱ����е�����ת����ͼ�����棬�ͻᷢ��Ҫ�������Ҫ����ɽ�Ⱥ͹��֣���Ȼ������ˣ�Ŀ���Ƿ����ҵ����еĹ��ֺ� 
Ѱ��һ�������ڳ�����һ������ʱ����ߵ�ɽ�壬����������Ǹù��ֲ�������������ˣ�����������Ӽ��������� 
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
��һ�������Ǿ������Է�������������һ�����־ͺ����ڵ���һֱ����֪��������һ�����֣�����Ҳ���ܳ����Ľ���ģ�ʱ�临�Ӷ�O(n)�� 
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
