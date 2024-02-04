#include <bits/stdc++.h>
using namespace std;

int dst[100];
int adjMat[100][100];
bool isVisited[100][100];
int level[100][100];
int n, m;
vector<pair<int, int>> d = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};

bool isValid(int i, int j)
{
    return !isVisited[i][j] && i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int Ki, int Kj)
{
    queue<pair<int, int>> Q;
    Q.push({Ki, Kj});
    isVisited[Ki][Kj] = true;
    level[Ki][Kj] = 0;

    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;

            if (isValid(ci, cj))
            {
                Q.push({ci, cj});
                isVisited[ci][cj] = true;
                level[ci][cj] = level[parent.first][parent.second] + 1;
            }
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int Ki, Kj, Qi, Qj;
        cin >> n >> m >> Ki >> Kj >> Qi >> Qj;
        memset(isVisited, false, sizeof(isVisited));
        memset(level, -1, sizeof(level));
        bfs(Ki, Kj);
        cout << level[Qi][Qj] << endl;
    }

    return 0;
}