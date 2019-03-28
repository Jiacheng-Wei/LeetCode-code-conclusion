#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

    int minlength(string str1,string str2)
    {
        int length1=str1.length();
        int length2=str2.length();
        if (length1>=length2) return length2;
        else return length1;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0]; 
        string prefix,longestprefix;
        for (int j=0;j<minlength(strs[0],strs[1]);j++)
        {
            if(strs[0][j]==strs[1][j])
            {
                prefix.push_back(strs[0][j]);
            }
            else break;
        }
        //cout<<prefix;
        //if (prefix.empty()) return "";
        if	(strs.size()==2) return prefix;
        for (int i=2;i<strs.size();i++)
        {
            for (int j=0;j<minlength(strs[i],prefix);j++)
            {
                if (prefix[j]==strs[i][j])
                {
                    longestprefix.push_back(prefix[j]);
                }
                else break;
            }
            if (longestprefix.length()==0) return "";
            if(i!=strs.size()-1)
            {
                prefix.clear();
                prefix=longestprefix;
                longestprefix.clear();
            }
        }
        //string longestprefix="fjakfalj";
        return longestprefix;
    }
	int main()
	{
		vector<string> strs;
		strs.push_back("flower");
		strs.push_back("flow");
		strs.push_back("flight");
		//cout<<minlength(strs[0],strs[1]);
		//cout<<strs.size();
		//for (int i=0;i<3;i++)
		//{
		//	cout<<strs[i]<<endl;
		//}
		//cout<<strs[1].length(); 
		cout<<longestCommonPrefix(strs);
		return 0;
	 } 
	 //当定义string类型的变量时，要在字符串后面添加元素时只能用push_back(),不能用“+”和“append()”，也不能直接用“=”赋值，我就犯了这个错误
	 //因为在延长字符串时，后面的存储空间还没有给出来，所以没有地址，所以不要傻不拉几的用“=”一个一个给字符串元素赋值。 
