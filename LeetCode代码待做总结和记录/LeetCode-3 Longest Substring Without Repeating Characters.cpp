class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.length();
        if (length==0) return 0;
        int ans=INT_MIN,i=0,j=0;
        unordered_set<char> st;
        while (i<length&&j<length)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j++]);
                ans=max(ans,j-i);
            }
            else 
            {
                st.erase(s[i++]);
            }
        }
        return ans;
    }
};
//sliding windows���ǳ�����������ַ����ļ�����Ϣ��һ������Χ�ĳ���������ķ�����ʱ�临�Ӷ�ΪO(2n)=O(n)�ķ��������ǻ��ǿ��Խ����Ż��� 
/*
The naive approach is very straightforward. But it is too slow. So how can we optimize it?
In the naive approaches, we repeatedly check a substring to see if it has duplicate character. But it is unnecessary. If a substring s_{ij}s 
ij from index i to j - 1 is already checked to have no duplicate characters. We only need to check if s[j]s[j] is already in the substring s_{ij}
 sij
To check if a character is already in the substring, we can scan the substring, which leads to an 
O(n^2) algorithm. But we can do better.
By using HashSet as a sliding window, checking if a character in the current can be done in O(1)O(1).
A sliding window is an abstract concept commonly used in array/string problems. A window is a range of elements in the array/string which 
usually defined by the start and end indices, i.e. [i, j)[i,j) (left-closed, right-open). A sliding window is a window "slides" its two 
boundaries to the certain direction. For example, if we slide [i, j)[i,j) to the right by 11 element, then it becomes [i+1, j+1)[i+1,j+1) 
(left-closed, right-open).
Back to our problem. We use HashSet to store the characters in current window [i, j)[i,j) (j = ij=i initially). Then we slide the index jj 
to the right. If it is not in the HashSet, we slide jj further. Doing so until s[j] is already in the HashSet. At this point, we found the 
maximum size of substrings without duplicate characters start with index i. If we do this for all i, we get our answer.
*/ 
/*���������ķ�����ʹ��set�����ڼ�⵽�ظ�ֵʱ��������������ÿһ��Ԫ�ؽ����жϣ�������ķ���ʹ����hashmap��ͨ���洢indexֵ���������ظ���ֵʱ��
����ֱ�ӻ������ظ�ֵ�ĺ�һ��λ��*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.length();
        if (length==0) return 0;
        int ans=INT_MIN,i=0,j=0;
        unordered_map<char, int> mp;
        while (i<length&&j<length)
        {
            if(mp.find(s[j])!=mp.end())
            {
                i=max(mp.find(s[j])->second,i);
            }
            ans=max(ans,j-i+1);
            mp[s[j]]=j+1;//���㵱�ַ�����ֻ��һ��Ԫ��ʱ���������Ϊ0
            j++;
        }
        return ans;
    }
}; 


