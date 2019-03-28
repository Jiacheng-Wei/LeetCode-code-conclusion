/*
做这道题的方法是，我的比较复杂，通过遍历了整个数组，然后对每一个元素去寻找他与他相加等于target的值，寻找值的方法是
利用二分法去做，但是这样的时间复杂度应该是O(nlogn)。 
*/ 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.empty()||numbers.size()==1) return res;
        for (int i=0;i<numbers.size();i++)
        {
            if (numbers[i]>target) break;
            else if(binarySearch(numbers,i+1,target-numbers[i])!=-1)
            {
                res.push_back(i+1);
                res.push_back(binarySearch(numbers,i+1,target-numbers[i])+1);
                break;
            }
            else continue;
        }
        return res;
    }
    int binarySearch(vector<int>& numbers, int left, int target){
        int right=numbers.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if(numbers[mid]==target) return mid;
            else if(numbers[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};
//方法一样，代码量更小O(nlgn)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int t = target - numbers[i], left = i + 1, right = numbers.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t) return {i + 1, mid + 1};
                else if (numbers[mid] < t) left = mid + 1;
                else right = mid;
            }
        }
        return {};
    }
};
/*
但是上面那种方法并不efficient，时间复杂度是O(nlgn)，我们再来看一种O(n)的解法，我们只需要两个指针，一个指向开头，
一个指向末尾，然后向中间遍历，如果指向的两个数相加正好等于target的话，直接返回两个指针的位置即可，若小于target，
左指针右移一位，若大于target，右指针左移一位，以此类推直至两个指针相遇停止，参见代码如下：
*/ 
// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            else if (sum < target) ++l;
            else --r;
        }
        return {};
    }
};
