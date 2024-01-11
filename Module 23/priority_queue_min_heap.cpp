#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> priorityQueue; // min heap follow kortase.
    while (true)
    {
        int command;
        cin >> command;
        if (command == 0)
        {
            int value;
            cin >> (value);
            priorityQueue.push(value); // O(logN)
        }
        else if (command == 1)
        {
            priorityQueue.pop(); // O(logN)
        }
        else if (command == 2)
        {
            cout << priorityQueue.top() << endl; // O(1)
        }
        else
        {
            break;
        }
    }

    return 0;
}