#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int flor[N][N];
int visited[N][N];
int n, m;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return !visited[i][j] && flor[i][j] != -1 && i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(pair<int, int> src)
{
    int roomCount = 0;
    queue<pair<int, int>> Q;
    Q.push(src);

    visited[src.first][src.second] = true;

    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        Q.pop();
        roomCount++;

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;

            if (isValid(ci, cj))
            {
                Q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
    return roomCount;
}

int main()
{
    cin >> n >> m;
    pair<int, int> src, des;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                flor[i][j] = -1;
            }
        }
    }

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && flor[i][j] != -1)
            {
                v.push_back(bfs({i, j}));
            }
        }
    }

    if (v.empty())
        cout << 0 << endl;

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    return 0;
}
