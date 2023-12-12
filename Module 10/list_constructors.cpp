#include <bits/stdc++.h>
using namespace std;
int main()
{
    // list<int>myList();

    /*
    // copy from list
    list<int> myList = {1, 2, 3, 4, 5};
    list<int> mylist_2(myList);
    */

    /*
    // copy from array
    int a[5] = {10, 20, 30, 40, 50};
    list<int> mylist_2(a, a + 5);
    */

    // copy from vector
    vector<int> v = {100, 200, 300, 400, 500};
    list<int> mylist_2(v.begin(), v.end());

    /*
    // output from list
    for (auto it = mylist_2.begin(); it != mylist_2.end(); it++)
    {
        cout << *it << " ";
    }
    */

    // shortcut output from list
    for (int value : mylist_2)
    {
        cout << value << " ";
    }
    return 0;
}