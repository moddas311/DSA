#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> sorted_v(v);
        sort(sorted_v.begin(), sorted_v.end());
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != sorted_v[i])
            {
                flag = false;
            }
        }
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}