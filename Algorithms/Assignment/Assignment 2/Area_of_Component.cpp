#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, m;
const int N = 1005;
bool isVisited[N][N];
char mat[N][N];
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int ci, int cj)
{
    return !isVisited[ci][cj] && ci >= 1 && ci <= n && cj >= 1 && cj <= m && mat[ci][cj] != '-';
}

int bfs(int si, int sj)
{
    int cunt = 0;
    queue<pair<int, int>> Q;
    Q.push({si, sj});
    isVisited[si][sj] = true;

    while (!Q.empty())
    {
        cunt++;
        pair<int, int> parent = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;

            if (isValid(ci, cj))
            {
                Q.push({ci, cj});
                isVisited[ci][cj] = true;
            }
        }
    }
    return cunt;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            isVisited[i][j] = false;
        }
    }

    int cunt = 0;
    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!isVisited[i][j] && mat[i][j] == '.')
            {
                int cnt = bfs(i, j);
                if (cnt >= 1)
                {
                    v.push_back(cnt);
                }
            }
        }
    }

    if (v.empty())
        cout << -1 << endl;

    else
    {
        int mn = v[0];

        for (int value : v)
        {
            mn = min(value, mn);
        }
        cout << mn << endl;
    }
    return 0;
}