#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length=digits.size();
        digits[length-1]+=1;
        for(int i=length-1;i>0;i--)
		//注意这里i的判断一定要大于0，不能是大于等于0，否则如果第一位大于0时，在这一步就已经被取余了，下一步就没法判断 
        {
            if (digits[i]>=10) 
            {
                digits[i]=digits[i]%10;
                digits[i-1]=digits[i-1]+1;
            }
            else break;
        }
        if (digits[0]>=10)
        {
            digits[0]=digits[0]%10;
            digits.insert(digits.begin(),1);
        }
        //digits.insert(digits.begin(),1);
        return digits;
    }
};

int main()
{
	vector<int> dig;
	/*int a;
	while (scanf("%d",&a)!=EOF)
	{
		dig.push_back(a);
	}*/
	dig.push_back(9);
	dig.push_back(9);
	//dig.push_back(3);
	//dig.push_back(4);
	Solution s; 
	s.plusOne(dig);
	for (int i=0;i<dig.size();i++)
	{
		cout<<dig[i];
	}
	return 0;
 } 
