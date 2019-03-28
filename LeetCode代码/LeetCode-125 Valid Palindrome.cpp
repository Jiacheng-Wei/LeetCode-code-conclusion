#include<stdlib.h>
#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length()<=1) return true;
		for (int i=0;i<s.length();i++)
        {
            if (s[i]>='A'&&s[i]<='Z')
            {
            	s[i]=s[i]+32;
			}
        } 
        int i=0;
        int j=s.length()-1;
        while (i<=j)
        {
            if((s[i]<'a'||s[i]>'z')&&(s[i]<'0'||s[i]>'9'))//注意中间一定是&&符 
            {
                i++;
            }
            else if((s[j]<'a'||s[j]>'z')&&(s[j]<'0'||s[j]>'9'))
            {
                j--;
            }
            else 
            {
                if(s[i]==s[j])
				{
					i++;
                	j--;
				}
                //continue;
                else return false;
            }
        }
        return true;
    }
}; 

/*class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(len <= 1)return true;
        int i = 0, j = len - 1;
        while(i <= j) {
            if(isAlphanumeric(s[i]) == false)
                i++;
            else if(isAlphanumeric(s[j]) == false)
                j--;
            else {
                if(isSame(s[i], s[j]) == true)
                    {i++; j--;}
                else return false;
            }
        }
        return true;
    }
    bool isAlphanumeric(char c) {
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9'))
            return true;
        else 
            return false;
    }
    bool isSame(char a, char b) {
        if(a >= 'A' && a <= 'Z')
            a += 32;
        if(b >= 'A' && b <= 'Z')
            b += 32;
        return a == b;
    }
};*/

int main()
{
	string s;
	cin>>s;
	Solution S;
	cout<<S.isPalindrome(s);
	return 0;
 } 
//注意的问题是，要考虑数字的成分，太操蛋了，竟然是逻辑判断符出错了。 
