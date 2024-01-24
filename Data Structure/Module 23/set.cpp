#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> SET;
    while (n--) // O(NlogN)
    {
        int value;
        cin >> value;
        SET.insert(value); // O(logN)
    }

    // for (auto it = SET.begin(); it != SET.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // count
    if (SET.count(10))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}