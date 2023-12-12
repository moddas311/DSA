#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList = {40, 60, 10, 20, 10, 90, 10, 80, 10};

    // myList.remove(10); // remove duplicate

    // myList.sort(); // sort ascending order
    // myList.sort(greater<int>()); // sort descending order

    // myList.unique(); // unique value gula thakbe just. tobe tar age sort kora thakte hbe.

    // myList.reverse(); // reverse korar jonno ei function use kora hoy.
    for (int value : myList)
    {
        cout << value << " ";
    }

    return 0;
}