class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        int length=s.length();
        for(int i=0;i<length-1;i++)
        {
            sum=sum+(s[i]-'A'+1);
            sum=sum*26;
        }
        sum=sum+s[length-1]-'A'+1;
        return sum;
    }
};
