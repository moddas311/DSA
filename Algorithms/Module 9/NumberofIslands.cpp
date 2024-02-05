/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of
islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/

class Solution
{
public:
    int n, m;
    bool vis[301][301];
    int ans = 0;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int ci, int cj)
    {
        return ci >= 0 && ci < n && cj >= 0 && cj < m;
    }

    void dfs(int si, int sj, vector<vector<char>> &grid)
    {
        vis[si][sj] = true;

        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1')
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
