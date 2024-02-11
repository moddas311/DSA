/*
Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/
class Solution
{
public:
    void dfs(int src, vector<bool> &isvisited, vector<int> &result, vector<int> adj[])
    {

        isvisited[src] = true;
        result.push_back(src);

        for (int child : adj[src])
        {
            if (!isvisited[child])
            {
                dfs(child, isvisited, result, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        int src = 0;
        vector<int> result;
        vector<bool> isvisited(V, false);

        dfs(src, isvisited, result, adj);

        return result;
    }
};