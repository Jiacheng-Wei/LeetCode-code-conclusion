/*
由于测试用例高达60000，所以为了避免超时，时间复杂度不能为O(n^2)，因此需要使用的方法是，先遍历每个数，然后取关于60的模后
存入到hash表中，然后在利用排列组合的方式计算模相加等于60的组数，有两种情况：
第一：
取模后为30和0的情况，这样就能产生n*(n-1)个队；
第二：
取模为其他数的情况，就判断60-x的组数然后相乘，但是要注意因为全遍历的缘故所以最终结果要除以二；我实现的方法比较简单，就是以
30为界进行遍历，这样就能避免重复的情况。 
*/ 
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        for(auto i:time){
            if(mp.find(i%60)==mp.end()) mp[i%60]=1;
            else mp[i%60]++;
        }
        int res=0;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(it->first==0||it->first==30) res+=(it->second*(it->second-1))/2;
            else if(it->first<30&&mp.find(60-it->first)!=mp.end()) res+=it->second*mp[60-it->first];
        }
        return res;
    }
};
//网友方法，还是巧妙
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int sum[100] = {0};
        for (int i = 0; i < time.size(); ++i) {
            sum[time[i] % 60] += 1;
        }
        int answer = sum[0] * (sum[0] - 1) / 2 + sum[30] * (sum[30] - 1) / 2;
        for (int i = 1; i < 30; ++i) {
            answer += sum[i] * sum[60 - i];
        }
        return answer;
    }
}; 
