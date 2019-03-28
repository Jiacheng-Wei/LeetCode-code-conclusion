//动态规划的一种形式，虽然没有什么数组存储每一步的结果，但是没进行一步四个参数值都在更新，而且这种方法也不一般化，很难实现扩展 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell1=0,sell2=0;
        int buy1=INT_MIN,buy2=INT_MIN;
        for (int i=0;i<prices.size();i++)
        {
            buy1=max(buy1,-prices[i]);
            sell1=max(sell1,buy1+prices[i]);
            buy2=max(buy2,sell1-prices[i]);
            sell2=max(sell2,buy2+prices[i]);
        }
        return sell2;
    }
};
/*
而这里我们需要两个递推公式来分别更新两个变量local和global，参见网友Code Ganker的博客，我们其实可以求至少k次交易的最大利润，
找到通解后可以设定 k = 2，即为本题的解答。我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖
出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：
local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
global[i][j] = max(local[i][j], global[i - 1][j])
其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，而全局最优比较局部最优
和前一天的全局最优。代码如下：
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size(),g[n][3]={0},l[n][3]={0};
        for (int i=1;i<n;i++)
        {
            int diff=prices[i]-prices[i-1];
            for(int j=1;j<3;j++)
            {
                l[i][j]=max(g[i-1][j-1]+max(diff,0),l[i-1][j]+diff);
                g[i][j]=max(g[i-1][j],l[i][j]);
            }
        }
        return g[n-1][2];
    }
};
/*二维数组的解法，这个解法可以优化到一维数组，可以极大的节省了空间，由于覆盖的顺序关系，我们需要j从2到1，这样可以取到正确的g[j-1]值，
而非已经被覆盖过的值，优化的地方，主要是diff的求解和要变为diff=prices[i+1]-prices[i],然后就是for循环的循环条件要变了 */
/*
这里是另一种解答方法： 
这里我们先解释最多可以进行k次交易的算法，然后最多进行两次我们只需要把k取成2即可。我们还是使用“局部最优和全局最优解法”。我们维护两种量，
一个是当前到达第i天可以最多进行j次交易，最好的利润是多少（global[i][j]），另一个是当前到达第i天，最多可进行j次交易，并且最后一次交易在当
天卖出的最好的利润是多少（local[i][j]）。下面我们来看递推式，全局的比较简单，
global[i][j]=max(local[i][j],global[i-1][j])，
也就是去当前局部最好的，和过往全局最好的中大的那个（因为最后一次交易如果包含当前天一定在局部最好的里面，否则一定在过往全局最优的里面）。
对于局部变量的维护，递推式是
local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)，
也就是看两个量，第一个是全局到i-1天进行j-1次交易，然后加上今天的交易，如果今天是赚钱的话（也就是前面只要j-1次交易，最后一次交易取当前天），
第二个量则是取local第i-1天j次交易，然后加上今天的差值（这里因为local[i-1][j]比如包含第i-1天卖出的交易，所以现在变成第i天卖出，并不会增加
交易次数，而且这里无论diff是不是大于0都一定要加上，因为否则就不满足local[i][j]必须在最后一天卖出的条件了）。
上面的算法中对于天数需要一次扫描，而每次要对交易次数进行递推式求解，所以时间复杂度是O(n*k)，如果是最多进行两次交易，那么复杂度还是O(n)。
空间上只需要维护当天数据皆可以，所以是O(k)，当k=2，则是O(1)。代码如下:
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size(),g[3]={0},l[3]={0};
        for (int i=0;i<n-1;i++)
        {
            int diff=prices[i+1]-prices[i];
            for(int j=2;j>0;j--)
            {
                l[j]=max(g[j-1]+max(diff,0),l[j]+diff);
                g[j]=max(g[j],l[j]);
            }
        }
        return g[2];
    }
};
