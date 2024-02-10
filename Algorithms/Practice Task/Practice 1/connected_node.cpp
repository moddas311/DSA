#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<int> mat[node];

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int n;
    cin >> n;
    int count = 0;

    for (int i = 0; i < mat[n].size(); i++)
        count++;

    cout << count << endl;
    return 0;
}