//不符合要求的代码，所以还是要自己造一下轮子 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};
//two pointer 求解
/*
题目中还要让只遍历一次数组来求解，那么我需要用双指针来做，分别从原数组的首尾往中心移动。
- 定义red指针指向开头位置，blue指针指向末尾位置
- 从头开始遍历原数组，如果遇到0，则交换该值和red指针指向的值，并将red指针后移一位。若遇到2，则交换该值和blue指针指向的值，并
将blue指针前移一位。若遇到1，则继续遍历。
*/
class Solution {
public:
    void sortColors(int A[], int n) {int red = 0, blue = n - 1;
        for (int i = 0; i <= blue; ++i) {
            if (A[i] == 0) {
                swap(A[i], A[red++]);
            } else if (A[i] == 2) {
                swap(A[i--], A[blue--]);
            } 
        }
    }
}; 
/*
计数排序，需要遍历数组两遍，那么先来看这种方法，因为数组中只有三个不同的元素，所以实现起来很容易。
- 首先遍历一遍原数组，分别记录0,1,2的个数
- 然后更新原数组，按个数分别赋上0，1，2
*/ 
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0}, idx = 0;
        for (int i = 0; i < n; ++i) ++count[A[i]];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                A[idx++] = i;
            }
        }
    }
};

