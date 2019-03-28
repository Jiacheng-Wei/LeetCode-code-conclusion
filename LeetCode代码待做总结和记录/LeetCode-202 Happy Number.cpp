#include<iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n != 1) {
        	int sum = 0;
        	while(n > 0) {
        		sum += ( (n % 10) * (n % 10) );
        		n /= 10;
        	}
        	n = sum;
        	if(s.find(n) != s.end()) break;
        	else 
        		s.insert(n);
        }
        return n == 1;
    }
};

int main()
{
	int n=2;
	Solution s;
	cout<<s.isHappy(n);
	return 0;
 } 
 /*
 �ر�ע�⣺�ȣ�����map���������ֵ���map���������ĳ����ֵ���᷵��map��end��
Ȼ�������ִ˼�ֵû���ҵ�(_Where == this->end())�Ļ���
���Զ���ĩβ���루this->insert(_Where��һ����������ļ�ֵ��value��Ĭ��ֵ��mapped_type()�����ɵĶԶ���pair����
Ȼ�󷵻�����������ֵ��second������first������int��Ĭ�Ϲ��캯��int()������0��
Ҳ����ʱ��������û�ж�map���в������������ֻ����[]�ж����·���ֵ�Ƿ���0��map����Ҳ���Զ����һ�
����һ���ж�map�Ƿ����һ����������map��find�������ж�find�ķ��ؽ���Ƿ���map��end��

 */
