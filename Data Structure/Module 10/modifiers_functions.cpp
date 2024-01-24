#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList = {10, 20, 30, 40, 50, 60, 70, 30, 100, 30, 110, 30};
    // list<int> newList;

    // shortcut for copy
    // newList = myList;

    // longcut for copy
    // newList.assign(myList.begin(), myList.end());

    // remove element.
    /* myList.pop_back();
    myList.pop_front(); */

    // add element.
    /* myList.push_front(100);
    myList.push_back(200); */

    // kono index e element add kora.
    // myList.insert(next(myList.begin(), 2), 100); // 2 No. index e 100 insert kore dibe compllexity O(n).
    // ekta list copy kore onno ekta list er index e bosai dewa.
    // list<int> newList{60, 70, 80, 90, 100};
    // myList.insert(next(myList.begin(), 5), newList.begin(), newList.end()); // complexity o(n)k

    // index e kono element delete ba earse kora.
    // myList.erase(next(myList.begin(), 2)); // eikhane 2 No. index er value delete hoye jabe complexity O(n).
    // multiple value delete
    // myList.erase(next(myList.begin(), 2), next(myList.begin(), 5));

    // replace(myList.begin(), myList.end(), 30, 100);

    // for (int value : myList)
    // {
    //     cout << value << " ";
    // }

    auto it = find(myList.begin(), myList.end(), 110);
    if (it == myList.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    return 0;
}