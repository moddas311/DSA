#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            s.insert(value);
        }

        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}