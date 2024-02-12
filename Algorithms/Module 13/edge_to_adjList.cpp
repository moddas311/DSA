#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<pair<int, int>> adjLst[node];
    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjLst[u].push_back({v, w});
        // adjLst[v].push_back({u, w}); // eita hobe na cz eita eikta directed weighted graph.
    }

    for (int i = 0; i < node; i++)
    {
        cout << i << "->";
        for (pair<int, int> child : adjLst[i])
        {
            cout << "{" << child.first << "," << child.second << "}";
        }
        cout << endl;
    }
    return 0;
}