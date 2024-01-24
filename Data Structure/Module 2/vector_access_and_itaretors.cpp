#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 3, 5, 6, 7, 1, 2, 9};
    // vector<int>::iterator it;
    // cout << v[v.size() - 1];
    // cout << v.back();
    // cout<<v[0];
    // cout << v.front();
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}