#include <stdio.h>
#include <iostream>
#include <string>
using namespace std; 
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length()==0||s==" ") return 0;
        int length=s.length();
        int i=length-1;
        /*while (s[i]==' ') 
        {
            s.erase(s.end()-1);
            length=s.length();
        } */
        //这样只考虑了字符串后面只有一个空格的情况，但是若有多个空格就没办法解决，所以比需要要用下面的方法，跳过所有的空格在进行统计 
        while (s[i]==' '&&i>=0) 
        {
			i--;
        } 
        int num=0;
        while (s[i]!=' '&&i>=0)
        {
            
            num++;
            i--;
        }
        return num;
    }
};
int main()
{
	string s;
	cin>>s;
	Solution so; 
	cout<<so.lengthOfLastWord(s);
	return 0;
}
