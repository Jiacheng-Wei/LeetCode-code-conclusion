//brute force 时间复杂度为O(n^2)所以然后时间就炸了，480ms 
class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        if (n==0) return 0;
        for (int i=0;i<n-1;i++)
        {
            int right_max=0,left_max=0;
            for (int j=i;j>=0;j--)
            {
                left_max=max(left_max,height[j]);
            }
            for (int j=i;j<n;j++)
            {
                right_max=max(right_max,height[j]);
            }
            res=res+min(left_max,right_max)-height[i];
        }
        return res;
    } 
};
//dp解决，待更新，先给出标准答案，此答案时间复杂度是O(n) 
int trap(vector<int>& height)
{
	if(height == null)
		return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
//用栈解决问题，using stack：时间复杂度是O(n) 
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
} 
//using two pointer：时间复杂度是O(n)  ，总体思路自己复习时画一画流程图就知道了 
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
 
