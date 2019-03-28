/*
递归解法，主要思想是前后交换，需要注意的细节是交换元素的脚标要相互对应，同时要注意的是在执行的
时候要判断数组是否为空，后面的递归函数无法解决数组为空的情况 
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;
        reverse(s,0);
    }
    void reverse(vector<char>& s, int index)
    {
        if(index>(s.size()-1)/2) return;
        char temp=s[index];
        s[index]=s[s.size()-index-1];
        s[s.size()-index-1]=temp;
        reverse(s,index+1);
    }
};
//find a new solution which can avoid the mistake on the wrong index
class Solution {
public:
	void reverseString(vector<char>& s) {
      helper(0, s.size() - 1, s);
    }

    void helper(int start, int end, vector<char>&s) {
      if (start >= end) {
        return;
      } 
      // swap between the first and the last elements.
      char tmp = s[start];
      s[start] = s[end];
      s[end] = tmp;
       
      helper(start + 1, end - 1, s);
   }
} 
