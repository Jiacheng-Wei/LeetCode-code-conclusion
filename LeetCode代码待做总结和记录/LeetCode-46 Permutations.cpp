//ȫ���еĵݹ�ʵ�֣���Ҫע��������ǵ�30��31�У����ݹ鿪ʼ�ػ���ʱһ��Ҫ��mp��λtrue��ͬʱҪ��pos�е�ֵ��pop�� 
//���庯����ʵ����Ҫ�Ĳ���Ҫ���ݾ���������������ʱ�����Ҿ��ò���ȱ���Ǹ�map�����ж������Ƿ��Ѿ���ʹ�� 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int n=nums.size();
        vector<int> pos;
        map<int,bool> mp;
        for (int i=0;i<n;i++)
        {
            mp[nums[i]]=false;
        } 
        generate(0,n,mp,nums,pos,res);
        return res;
    }
    void generate(int index,int& n,map<int,bool>& mp,vector<int> nums,vector<int> pos,vector<vector<int> >& res)
    {
        if(index==n)
        {
            res.push_back(pos);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==false)
            {
                pos.push_back(nums[i]);
                mp[nums[i]]=true;
                generate(index+1,n,mp,nums,pos,res);
                mp[nums[i]]=false;
                pos.pop_back();
            }
        }
    }
};
//��һ�ֵݹ鷽ʽ�����ǲ�ͣ�Ľ���num��������֣�Ȼ��ݹ���ɺ�Ҳ��ʵ��ȫ����
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int> &num, int start, vector<vector<int> > &res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};
/*
���������һ�ַ��������ַ�����CareerCup���ϵķ�����Ҳͦ����ģ��������˼���������ģ�
��n=1ʱ��������ֻ��һ����a1����ȫ����ֻ��һ�֣���Ϊa1
��n=2ʱ�������д�ʱ��a1a2����ȫ���������֣�a1a2��a2a1����ô��ʱ���ǿ��Ǻ�������������Ĺ�ϵ�����Ƿ��֣���ʵ������a1��ǰ������λ�÷ֱ������a2
��n=3ʱ����������a1a2a3����ʱȫ���������֣��ֱ�Ϊa1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, �� a3a2a1����ô��������Ľ��ۣ�ʵ��������a1a2��a2a1
�Ļ������ڲ�ͬ��λ���ϼ���a3���õ��ġ�
_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3
_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3
Ҳ�ǵݹ�ʵ�ֵģ�������һ��������⣬��Ϊ����˼·Ҫ���ӵ�*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.empty()) return vector<vector<int> >(1, vector<int>());
        vector<vector<int> > res;
        int first = num[0];
        num.erase(num.begin());
        vector<vector<int> > words = permute(num);
        for (auto &a : words) {
            for (int i = 0; i <= a.size(); ++i) {
                a.insert(a.begin() + i, first);
                res.push_back(a);
                a.erase(a.begin() + i);
            }
        }   
        return res;
    }
}; 
