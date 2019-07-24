//https://leetcode-cn.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string::iterator it=s.begin();
        if(s.empty())
            return true;
        for(it;it!=s.end();++it)
        {
            if(*it=='('||*it=='{'||*it=='[')
                st.push(*it);
            else
            {
                if(st.empty())
                    return false;
                else
                {
                    if((st.top()=='['&&*it==']')||
                       (st.top()=='{'&&*it=='}')||
                       (st.top()=='('&&*it==')'))
                        st.pop();
                    else
                        return false;
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};

//https://leetcode-cn.com/problems/implement-stack-using-queues/
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
        int size=q1.size()-1;
        while(size--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ret=q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int size=q1.size()-1;
        while(size--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        return q1.front();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};

//https://leetcode-cn.com/problems/implement-queue-using-stacks/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int size=s1.size();
        while(size--)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int size=s1.size();
        while(size--)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret=s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
    private:
    stack<int> s1;
    stack<int> s2;
};
