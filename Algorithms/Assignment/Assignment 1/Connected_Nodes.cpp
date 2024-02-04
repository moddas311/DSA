#include <bits/stdc++.h>
using namespace std;

vector<int> mat[1010];

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        if (mat[x].empty())
        {
            cout << -1;
        }

        vector<int> v;

        for (int value : mat[x])
        {
            v.push_back(value);
        }

        sort(v.begin(), v.end(), greater<int>());

        for (int value : v)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
