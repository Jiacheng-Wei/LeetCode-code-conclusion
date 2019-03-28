//��Ԥ����ķ�����Ⱥ���λ�ʵ�������һ���ģ�������������Ĵʵ���keyֵ 
/*
�����������Ⱥ������ַ����������еĴ�λ�ʣ���ν�Ĵ�λ�ʾ��������ַ�������ĸ���ֵĴ�����һ����ֻ��λ�ò�ͬ������abc��bac, cba�����Ǿͻ�Ϊ��
λ�ʣ���ô��������ж������Ƿ��Ǵ�λ���أ����Ƿ�������Ѵ�λ�ʵ��ַ�˳���������У���ô��õ���ͬ�Ľ�������������������ж��Ƿ�Ϊ��λ�ʵķ�
�������ڴ�λ����������󶼻�õ���ͬ���ַ����������Դ���Ϊkey�������д�λ�ʶ����浽�ַ��������У�����key���ַ�������֮���ӳ�䣬����ٴ����
��res�м��ɣ������������
*/ 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> >res;
        map<string,vector<string> > mp;
        for(string str : strs)
        {
            string key=str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        for (auto a : mp)
        {
            res.push_back(a.second);
        }
        return res;
    }
};
//��������ķ��������Ǵ洢ÿһ����ĸ���ֵĴ�����Ȼ������ϳ��ַ�������������Ϊkey 
/*�������ֽⷨû���õ��������������Ч�ʣ�������һ����СΪ26��int������ͳ��ÿ����
�����ַ����ֵĴ�����Ȼ��int����תΪһ��Ψһ���ַ��������ַ����������ӳ�䣬�������ǾͲ��ø��ַ��������ˣ���������*/ 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> >res;
        map<string,vector<string> > mp;
        for(string str : strs)
        {
            string key="";
            vector<int> cnt(26,0);
            for (auto a : str) cnt[a-'a']++;
            for (int d : cnt) key+=to_string(d)+'#';
            mp[key].push_back(str);
        }
        for (auto a : mp)
        {
            res.push_back(a.second);
        }
        return res;
    }
};
