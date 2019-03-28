//方法一，插入值时，就将栈中的数字的顺序按照队列的顺序存放。 
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tp;
        if (!s1.empty())
        {
            tp=s1.top();
            s1.pop();
        }
        return tp;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
private:
    stack<int> s1,s2;
};
//方法二： 在pop的时候按照队列顺序排列，这种方法要特别注意的是front函数的定义，如果s1为空时，front是刚插入的值，如果s1不为空时且s2也为空，那么front
//始终为第一个输入的fx值，然后就是如果s2不为空了，那么就要返回s2.top()的值了。 
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty()) front=x;
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tp;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        tp=s2.top();
        s2.pop();
        return tp;
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty()) return s2.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
private:
    stack<int> s1,s2;
    int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
