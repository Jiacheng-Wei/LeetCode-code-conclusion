/*
�������������ǲ����ڱ��ģ�����ÿ�ε�K������ֶ��ڲ�ͣ�ı仯����ô������ʵֻ����ǰK������־Ϳ����ˣ�
�������ǿ���ʹ��һ����С��������ǰK�����֣����ټ��������ֺ���С�ѻ��Զ�����Ȼ�����������С����
������ȥ��������л���K�����֣����ص�ʱ��ֻ�践�ضѶ�Ԫ�ؼ��ɣ��μ��������£�
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
����Ҳ����ʹ��multiset��������������ظ������Զ�����Ĺ��ܣ�����Ҳ���Դﵽ��С�ѵ�Ч�����μ��������£�
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
 
