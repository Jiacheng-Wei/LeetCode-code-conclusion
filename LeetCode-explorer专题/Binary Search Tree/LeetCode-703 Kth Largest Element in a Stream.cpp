/*
而这道题的数组是不断在变大的，所以每次第K大的数字都在不停的变化。那么我们其实只关心前K大个数字就可以了，
所以我们可以使用一个最小堆来保存前K个数字，当再加入新数字后，最小堆会自动排序，然后把排序后的最小的那
个数字去除，则堆中还是K个数字，返回的时候只需返回堆顶元素即可，参见代码如下：
*/ 
class KthLargest {
private:
    priority_queue <int, vector<int>, greater<int> > q;
    int K;
public:
    KthLargest(int k, vector<int> nums) {
        for(int num : nums)
        {
            q.push(num);
            if(q.size()>k) q.pop();
        }
        K=k;
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>K) q.pop();
        return q.top();
    }
};
/*
我们也可以使用multiset来做，利用其可重复，且自动排序的功能，这样也可以达到最小堆的效果，参见代码如下：
*/
class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        for (int num : nums) {
            st.insert(num);
            if (st.size() > k) st.erase(st.begin());
        }
        K = k;
    }
    
    int add(int val) {
        st.insert(val);
        if (st.size() > K) st.erase(st.begin());
        return *st.begin();
    }

private:
    multiset<int> st;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
 
