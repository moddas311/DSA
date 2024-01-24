class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        queue<int> newQ;
        int lastElement;
        while (!q.empty())
        {
            int firstElement = q.front();
            q.pop();
            if (q.empty())
            {
                lastElement = firstElement; // last element.
                break;
            }
            newQ.push(firstElement);
        }
        q = newQ;
        return lastElement;
    }

    int top()
    {
        queue<int> newQ;
        int lastElement;
        while (!q.empty())
        {
            int firstElement = q.front();
            q.pop();
            if (q.empty())
            {
                lastElement = firstElement; // last element
            }
            newQ.push(firstElement);
        }
        q = newQ;
        return lastElement;
    }

    bool empty()
    {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */