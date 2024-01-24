#include <bits/stdc++.h>
using namespace std;

// left to right print
void print_left(list<int> myList)
{
    cout << "L"
         << " "
         << "->"
         << " ";
    for (int val : myList)
    {
        cout << val << " ";
    }
    cout << endl;
}

// right to left print
void print_right(list<int> myList)
{
    myList.reverse();
    cout << "R"
         << " "
         << "->"
         << " ";
    for (int val : myList)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    list<int> myList;
    int query;
    cin >> query;
    while (query--)
    {
        int index, value;
        cin >> index >> value;
        if (index == 0)
        {
            myList.push_front(value);
            print_left(myList);
            print_right(myList);
        }
        else if (index == 1)
        {
            myList.push_back(value);
            print_left(myList);
            print_right(myList);
        }
        else if (index == 2)
        {
            if (value >= 0 && value < myList.size())
            {
                auto it = next(myList.begin(), value);
                myList.erase(it);
            }
            print_left(myList);
            print_right(myList);
        }
    }
    return 0;
}
