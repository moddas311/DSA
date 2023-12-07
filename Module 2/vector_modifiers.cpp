#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> x = {10, 20, 30, 40}; // O(N)
    // vector <int> v={1, 2, 3}; // O(1)
    // v=x;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    x.pop_back();
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }

    return 0;
}