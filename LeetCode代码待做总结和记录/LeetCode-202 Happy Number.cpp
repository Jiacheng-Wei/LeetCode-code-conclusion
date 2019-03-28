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
 特别注意：先，会在map查找这个键值的项，map如果不包含某个键值，会返回map的end，
然后它发现此键值没有找到(_Where == this->end())的话，
会自动在末尾插入（this->insert(_Where）一个以你输入的键值和value的默认值（mapped_type()）构成的对儿（pair），
然后返回这个插入项的值（second，键是first）。而int的默认构造函数int()，就是0。
也就是时候，哪怕你没有对map进行插入操作，哪怕只是用[]判断了下返回值是否是0，map对象也会自动添加一项。
不过一般判断map是否包含一个键，是用map的find方法，判断find的返回结果是否是map的end。

 */
