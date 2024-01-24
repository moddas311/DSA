#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    vector<int> v = {1, 3, 8, 2, 5, 2, 10, 2, 5, 2};
    // replace(v.begin(), v.end(), 2, 11);
    replace(v.begin(), v.end() - 1, 2, 11);
    for (int x : v)
    {
        cout << x << " ";
    }
    */

    vector<int> v = {1, 3, 8, 2, 5, 2, 10, 2, 5, 2};
    auto it = find(v.begin(), v.end(), 200);
    if (it == v.end())
        cout << "Not Found";
    else
        cout << "Found";
    return 0;
}