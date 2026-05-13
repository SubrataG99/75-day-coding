/*
Problem name : << Mother Vertex >>

Given a directed graph with V vertices labeled from 0 to V-1 and a list of edges edges[][], where each edge is represented as [u, v] indicating a directed edge from vertex u to vertex v, find a Mother Vertex of the graph. A Mother Vertex is a vertex from which all other vertices can be reached.
If multiple such vertices exist, return the one with the smallest value.
If no such vertex exists, return -1.

Examples:

Input: V = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
Output: 0
Explanation: Vertices 0, 1, and 2 can each reach all other vertices in the graph. Among them, 0 is the smallest, so the output is 0.
  
Input: V = 3, edges[][] = [[0, 1], [2, 1]]
Output: -1
Explanation: No vertex can reach all other vertices in the graph. Hence, there is no Mother Vertex, and the output is -1.
*/

// ============================================= >> Solution
class Solution
{
    public:
    void dfsVertex(int v, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[v] = true;
        for(int neighbor : adj[v])
            if(!visited[neighbor])
                dfsVertex(neighbor, visited, adj);
    }
    
    int findMotherVertex(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V, false);
        int candidate = 0;
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                dfsVertex(i, visited, adj);
                candidate = i;
            }
        }
        fill(visited.begin(), visited.end(), false);
        dfsVertex(candidate, visited, adj);
        for(bool v : visited)
            if(!v)
                return -1;
        return candidate;
    }
};
