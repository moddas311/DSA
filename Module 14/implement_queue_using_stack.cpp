class MyQueue
{
public:
    stack<int> stk;
    MyQueue()
    {
    }

    void push(int x)
    {
        stk.push(x);
    }

    int pop()
    {
        stack<int> newStk;
        int lastElement;
        while (!stk.empty())
        {
            int firstElement = stk.top();
            stk.pop();
            if (stk.empty())
            {
                lastElement = firstElement;
                break;
            }
            newStk.push(firstElement);
        }
        while (!newStk.empty())
        {
            stk.push(newStk.top());
            newStk.pop();
        }
        return lastElement;
    }

    int peek()
    {
        stack<int> newStk;
        int lastElement;
        while (!stk.empty())
        {
            int firstElement = stk.top();
            stk.pop();
            if (stk.empty())
            {
                lastElement = firstElement;
            }
            newStk.push(firstElement);
        }
        while (!newStk.empty())
        {
            stk.push(newStk.top());
            newStk.pop();
        }
        return lastElement;
    }

    bool empty()
    {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */