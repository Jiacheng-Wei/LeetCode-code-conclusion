class Solution {
public:
    bool isValid(string s) {
        stack<char> parth;
        int length=s.length();
        for (int i=0;i<length;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                parth.push(s[i]);
            }
            else if(s[i]==')'||s[i]==']'||s[i]=='}')
            {
                if (parth.empty()) return false;
                else
                {
                    if (s[i]==')') 
                    {
                        if (parth.top()=='(') parth.pop();
                        else return false;
                    }
                    if (s[i]==']')
                    {
                        if (parth.top()=='[') parth.pop();
                        else return false;
                    }
                    if (s[i]=='}')
                    {
                        if (parth.top()=='{') parth.pop();
                        else return false;
                    }
                }
            }
        }
        if (parth.empty()) return true;
        else return false;
    }
};
//用栈解决的经典问题 
