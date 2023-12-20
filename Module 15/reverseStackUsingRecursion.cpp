void reverseStack(stack<int> &stk)
{
    // Write your code here
    if (stk.empty())
        return;
    int x = stk.top();
    stk.pop();
    reverseStack(stk);

    stack<int> copyStack;
    while (!stk.empty())
    {
        copyStack.push(stk.top());
        stk.pop();
    }

    copyStack.push(x);
    while (!copyStack.empty())
    {
        stk.push(copyStack.top());
        copyStack.pop();
    }
}