#include<iostream>
#include <string>
using namespace std;



char number[]={'0','1','2','3','4','5','6','7','8','9'};
class Solution {
public:
    string countAndSay(int n) {
        string num="1";//����Ҫ�����ʼ�� 
        string result;//���ý��������Ϊ���м����Ҫ�����������ǵ�������ÿһ��nֵ����Ӧ�Ľ�� 
        if (n==1) return num;
        for (int i=1;i<n;i++)
        {
            //if(i==1) result="11";//ע����һ������д�������ڽ���е�����2ʱ�ͳ�����1111�Ľ����Ȼ���Ӱ�쵽��������н��,ԭ������25,26�л��������ֵ 
			for (int j=0;j<num.length();j++)
            {
                int nums=1;//��ʼ��Ϊ1���Խ����ֻ����һ��ֵ��ʱ������ж�û����ֵͬ������Ϊ1�� 
                while(j+1!=num.size()&&num[j]==num[j+1])//���������ж�����ʹ�ÿ��Խ�����һ��ֵ�������nums=1����������Եģ�����������ƺ�ֻ�����������������Ϊ�漰��˳������ 
                {
                    nums++;
                    j++;
                }
                result.push_back(number[nums]);
                result.push_back(num[j]);
            }
            num=result;
            result.clear();//�������ǽ����л� 
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
/*�����һ��Ҫ�ܽᣬ����ˢLeetCode������������õ�һ���⣬����ͨ���������ѧ�����������Dev�ı������ԣ���tool��compiler option�Ĵ�������/�Ż��µĴ�
�����ɵ����Ա�׼���棬����ΪiOS c++11��׼���ɣ������������д����ʱһ��Ҫ�Ȼ�����˼ά��ͼ��Ȼ�������⣬Ȼ�������������е�ÿһ��ע�͡�*/ 
