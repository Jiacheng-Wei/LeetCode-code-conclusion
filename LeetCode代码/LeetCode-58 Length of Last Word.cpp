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
        //����ֻ�������ַ�������ֻ��һ���ո��������������ж���ո��û�취��������Ա���ҪҪ������ķ������������еĿո��ڽ���ͳ�� 
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
