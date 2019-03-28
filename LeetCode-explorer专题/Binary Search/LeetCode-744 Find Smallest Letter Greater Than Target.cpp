//适用的模型是，寻找第一个大于他的值 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back()<=target||letters.front()>target) return letters.front();
        int left=0,right=letters.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(letters[mid]>target)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return letters[left];
    }
};
//二分问题一如既往注意边界问题 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back()<=target||letters.front()>target) return letters.front();
        int left=0,right=letters.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(letters[mid]>target)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return letters[right];
    }
};
