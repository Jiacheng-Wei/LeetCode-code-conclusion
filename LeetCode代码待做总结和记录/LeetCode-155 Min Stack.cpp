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
        elements.pop();//这一句和上一句一定要按这个顺序，因为需要elements.top()和min.top()的值比较，所以如果先elements.pop()则其top值就会改变。 
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
 //该题的做题思路是声明并初始化两个栈，一个元素栈，一个最小数栈，最小数栈按push顺序存入最小的元素。 
