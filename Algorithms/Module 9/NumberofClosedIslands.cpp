/*
Problem: Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.
*/

class Solution
{
public:
    int n, m;
    bool vis[105][105];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int ci, int cj)
    {
        return ci >= 0 && ci < n && cj >= 0 && cj < m;
    }

    bool flag;

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;

        if (si == 0 || si == n - 1 || sj == 0 || sj == m - 1)
            flag = false;

        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if (flag == true)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};