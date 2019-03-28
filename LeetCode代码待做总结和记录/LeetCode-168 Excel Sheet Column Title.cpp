class Solution {
public:
    string convertToTitle(int n) {
        stack<char> answ;
        string ans;
        while (n>0)
        {
            int m=n%26;
            if(m==0)
            {
                answ.push('Z');
                n--;
            }
            else 
            {
                answ.push(m-1+'A');
            }
            n=n/26;
        }
        while (!answ.empty())
        {
            ans.push_back(answ.top());
            answ.pop();
        }
        return ans;
    }
};
//这个方法怎么说，太巧妙了，很难想到，做积累吧 
