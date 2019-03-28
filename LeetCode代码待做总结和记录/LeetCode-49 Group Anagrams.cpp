//用预排序的方法，群组错位词的排序是一样的，就用这个排序后的词当做key值 
/*
这道题让我们群组给定字符串集中所有的错位词，所谓的错位词就是两个字符串中字母出现的次数都一样，只是位置不同，比如abc，bac, cba等它们就互为错
位词，那么我们如何判断两者是否是错位词呢，我们发现如果把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方
法，由于错位词重新排序后都会得到相同的字符串，我们以此作为key，将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射，最后再存入结
果res中即可，擦巾代码如下
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
//不用排序的方法，但是存储每一个字母出现的次数，然后将其组合成字符串，并令其作为key 
/*下面这种解法没有用到排序，提高了运算效率，我们用一个大小为26的int数组来统计每个单
词中字符出现的次数，然后将int数组转为一个唯一的字符串，跟字符串数组进行映射，这样我们就不用给字符串排序了，代码如下*/ 
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
