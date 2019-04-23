/*
���ڲ��������ߴ�60000������Ϊ�˱��ⳬʱ��ʱ�临�ӶȲ���ΪO(n^2)�������Ҫʹ�õķ����ǣ��ȱ���ÿ������Ȼ��ȡ����60��ģ��
���뵽hash���У�Ȼ��������������ϵķ�ʽ����ģ��ӵ���60�������������������
��һ��
ȡģ��Ϊ30��0��������������ܲ���n*(n-1)���ӣ�
�ڶ���
ȡģΪ����������������ж�60-x������Ȼ����ˣ�����Ҫע����Ϊȫ������Ե���������ս��Ҫ���Զ�����ʵ�ֵķ����Ƚϼ򵥣�������
30Ϊ����б������������ܱ����ظ�������� 
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
//���ѷ�������������
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
