#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList = {10, 20, 30, 40, 50};
    cout << myList.front();           // head er elemnt accesss korar jonno.
    cout << myList.back();            // tail er element access korar jonno.
    cout << *next(myList.begin(), 3); // onno index er element access korar jonno.
    return 0;
}