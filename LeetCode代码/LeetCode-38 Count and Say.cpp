#include<iostream>
#include <string>
using namespace std;



char number[]={'0','1','2','3','4','5','6','7','8','9'};
class Solution {
public:
    string countAndSay(int n) {
        string num="1";//首先要将其初始化 
        string result;//设置结果数组是为了中间必须要交换，方法是迭代生成每一个n值所对应的结果 
        if (n==1) return num;
        for (int i=1;i<n;i++)
        {
            //if(i==1) result="11";//注意这一步不能写，否则在结果中当输入2时就出现了1111的结果，然后会影响到后面的所有结果,原因在于25,26行会继续插入值 
			for (int j=0;j<num.length();j++)
            {
                int nums=1;//初始即为1可以解决当只出现一个值的时候，向后判断没有相同值，即就为1。 
                while(j+1!=num.size()&&num[j]==num[j+1])//设置两个判断条件使得可以解决最后一个值的情况和nums=1的设置是配对的，而且这道题似乎只能设置这种情况，因为涉及到顺序问题 
                {
                    nums++;
                    j++;
                }
                result.push_back(number[nums]);
                result.push_back(num[j]);
            }
            num=result;
            result.clear();//这两步是进行切换 
        }
        return num;
    }
/*    string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur +=std::to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}*/
};
 int main()
 {
 	int n;
 	cin>>n;
 	Solution s;
 	cout<<s.countAndSay(n);
 	return 0;
  } 
/*这个题一定要总结，这是刷LeetCode的以来做的最久的一道题，首先通过这道题我学会了如何设置Dev的编译语言，在tool的compiler option的代码生成/优化下的代
码生成的语言标准里面，设置为iOS c++11标准即可；其二，就是在写代码时一定要先画出来思维框图，然后在做题，然后就是详见代码中的每一步注释。*/ 
