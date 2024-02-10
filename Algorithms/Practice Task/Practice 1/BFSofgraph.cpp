/*
Question: Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the
graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take
nodes directly or indirectly connected from Node 0 in consideration.
*/

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> result;
        vector<bool> vis(V, false);
        queue<int> Q;

        Q.push(0);

        while (!Q.empty())
        {
            int parent = Q.front();
            Q.pop();
            result.push_back(parent);
            vis[parent] = true;

            for (int child : adj[parent])
            {
                if (!vis[child])
                {
                    Q.push(child);
                    vis[child] = true;
                }
            }
        }
        return result;
    }
};