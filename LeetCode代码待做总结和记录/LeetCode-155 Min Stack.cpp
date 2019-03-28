class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        elements.push(x);
        if (min.empty()||x<=min.top()) min.push(x);
    }
    
    void pop() {
        if(elements.empty()) return;
        if (elements.top()==min.top()) min.pop();
        elements.pop();//��һ�����һ��һ��Ҫ�����˳����Ϊ��Ҫelements.top()��min.top()��ֵ�Ƚϣ����������elements.pop()����topֵ�ͻ�ı䡣 
    }
    
    int top() {
        return elements.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> elements;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 //���������˼·����������ʼ������ջ��һ��Ԫ��ջ��һ����С��ջ����С��ջ��push˳�������С��Ԫ�ء� 
