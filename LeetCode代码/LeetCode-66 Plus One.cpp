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
		//ע������i���ж�һ��Ҫ����0�������Ǵ��ڵ���0�����������һλ����0ʱ������һ�����Ѿ���ȡ���ˣ���һ����û���ж� 
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
