//����һ��ͬ������������ʵ�֣���pushʱ�����ն��е�˳�����У�����popʱ����q2ʵ�ֶ�q1���һ��Ԫ�صķ��غ͵�����(Two Queues, push - O(1), pop O(n) )
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top;
        if (!q1.empty())
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            top=q1.front();
            q1.pop();
            queue<int> temp=q1;
            q1=q2;
            q2=temp;
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
private:
    queue<int> q1,q2;
}; 
//������������������ʵ�֣�ʵ�ֵķ����ǣ���������������push�������ö���2ʵ�ֶ���1��ջ˳�����С� Two Queues, push O(n), pop O(1)
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top;
        if (!q1.empty())
        {
            top=q1.front();
            q1.pop();
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
private:
    queue<int> q1,q2;
};
//��������һ������ʵ�֣���ѭ���ķ�ʽ��ʵ�ֶ��е�˳��ת��
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        for (int i=0;i<q1.size()-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top;
        if (!q1.empty())
        {
            top=q1.front();
            q1.pop();
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
}; 

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
