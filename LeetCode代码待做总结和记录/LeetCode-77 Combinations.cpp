//dfs���Ĺ���Ҫ��ȫ���е���ȣ����ǵĲ�ͬ���� forѭ���е�dfs���õ���ʼֵһ��Ϊi+1�������ܱ�֤���ظ� 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> pos;
        vector<vector<int> > res;
        dfs(n,k,1,pos,res);
        return res;
    }
    void dfs(int& n,int& k,int index,vector<int>& pos,vector<vector<int> >& res)
    {
        if (pos.size()==k) 
        {
            res.push_back(pos);
            return;
        }
        for (int i=index;i<=n;i++)
        {
            pos.push_back(i);
            dfs(n,k,i+1,pos,res);
            pos.pop_back();
        }
    }
};
/*
����������һ�ֵݹ��д�����˽ⷨû��helper���ݹ麯�������ǰѱ���͵����˵ݹ麯����д����ʮ�ֵļ�࣬Ҳ�Ƿǳ���Ȥ��һ�ֽⷨ��
����ⷨ�õ���һ����Ҫ������ C(n, k) = C(n-1, k-1) + C(n-1, k)����Ӧ�������Ǹ���ʱ��ѧ������ϵ�ʱ��ѧ���ɣ�����Ҳ�ǲ����ˡ�
��֮������һ�¾��ǣ���n������ȡk����������������������n-1������ȡk-1���������������ټ�����n-1������ȡk��������������֮
�͡����ﲩ���Ͳ�֤���ˣ���Ϊ��Ҳ���ᣬ��ֱ�Ӿ���Ŀ�е�������˵���ɣ�
C(4, 2) = C(3, 1) + C(3, 2)
���ǲ���д�� C(3, 1) �����������[1], [2], [3]������ C(3, 2) �����������[1, 2], [1, 3], [2, 3]��
���Ƿ��ֶ��߼�����Ϊ6�������� C(4, 2) �ĸ���֮�͡�����������ϸ���ᷢ�֣�C(3, 2)��������������� C(4, 2) ֮�У�
���� C(3, 1) ��ÿ�����ֻ��һ�����֣���������Ҫ�Ľ��k=2����ʵ�ܺð죬ÿ��������涼����4�����Ǳ���ˣ�[1, 4], [2, 4], [3, 4]������C(3, 2) 
�����������[1, 2], [1, 3], [2, 3]�����þ͵õ��� n=4, k=2 ����������ˡ��μ��������£�
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n<0||k<0) return {};
        if(k==0) return {{}};
        vector<vector<int> > res=combine(n-1,k-1);
        for (auto &a : res) a.push_back(n);
        for (auto &a : combine(n-1,k)) res.push_back(a);
        return res;
    }
};
//�����ķ���
/*
����������һ�ֵ�����д����Ҳ��һ�ֱȽ�����ķ���������ÿ���ȵ������ұߵ����֣�������res�У����ұߵ����ֳ�����n��
����������ߵ����֣�Ȼ�󽫵�ǰ���鸳ֵΪ��ߵ����֣������������ֱ������ߵ�����Ҳ������n��ֹͣѭ��������n=4, k=2ʱ��������˳��������ʾ
0 0 #initialization
1 0
1 1 
1 2 #push_back
1 3 #push_back
1 4 #push_back
1 5
2 5
2 2 
2 3 #push_back
2 4 #push_back
...
3 4 #push_back
3 5
4 5
4 4
4 5
5 5 #stop 
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) --i;
            else if (i == k - 1) res.push_back(out);
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
}; 
