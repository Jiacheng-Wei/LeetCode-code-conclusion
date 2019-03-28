/*
�ݹ�ⷨ����Ҫ˼����ǰ�󽻻�����Ҫע���ϸ���ǽ���Ԫ�صĽű�Ҫ�໥��Ӧ��ͬʱҪע�������ִ�е�
ʱ��Ҫ�ж������Ƿ�Ϊ�գ�����ĵݹ麯���޷��������Ϊ�յ���� 
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
