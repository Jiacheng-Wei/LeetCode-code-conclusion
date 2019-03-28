//STL模板解 4ms 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=string::npos)
        {
            return haystack.find(needle);
        }
        else return -1;
    }
}; 
//自己造轮子是有点慢跑了348ms
class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1=haystack.length();
        int length2=needle.length();
        int i=0;
        if (length2==0) return 0;
        for (i;i<length1;i++)
        {
            int j=0;
            if (haystack[i]==needle[0])
            {
                for (j=1;j<length2;j++)
                {
                    if(haystack[i+j]==needle[j]) continue;
                    else break;
                }
                if (j==length2) return i;
            }
        }
        if (i==length1) return -1;     
    }
}; 
