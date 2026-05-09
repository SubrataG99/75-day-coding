/*
Problem name : << Count Spanning Trees in a Graph >>

Given a connected undirected graph with n vertices and m edges, where each edge is represented as edges[i]=[u,v]  indicating an edge between vertices u and v. Determine the total number of distinct spanning trees that can be formed from the graph.
Note: A spanning tree is a subgraph of the given graph that includes all n vertices, has exactly n-1 edges, is connected, and contains no cycles; therefore, every connected undirected graph always has at least one spanning tree.

Examples:

Input: n = 6, edges = [[0, 3], [0, 1], [1, 2], [1, 5], [3, 4]]
Output: 1
Explanation: The graph has 6 vertices and 5 edges, and it is connected, so it is already a tree (m = n-1). A tree has only one spanning tree, which is the graph itself, so the answer is 1.
  
Input: n = 3, edges = [[0, 1], [0, 2], [1, 2]]
Output: 3
Explanation: There are exactly 3 possible spanning trees for the given graph. 
 
Input: n = 1, edges = []
Output: 1
Explanation: With 1 vertex, a spanning tree needs 0 edges. The graph already satisfies this, so the answer is 1.
*/

// =================================================== >> Solution
class Solution
{
    public:
    double det(vector<vector<double>>& a, int n)
    {
        double res = 1.0;
        int N = n;
        for (int i = 0; i < N; i++) {
            // Find pivot
            int pivot = i;
            for (int j = i; j < N; j++)
                if (abs(a[j][i]) > abs(a[pivot][i]))
                    pivot = j;
            if (abs(a[pivot][i]) < 1e-9) return 0.0;
            // Swap rows
            if (pivot != i)
            {
                swap(a[i], a[pivot]);
                res = -res;
            }
            res *= a[i][i];
            // Eliminate using floating point
            for (int j = i + 1; j < N; j++)
            {
                double factor = a[j][i] / a[i][i];
                for (int k = i; k < N; k++)
                    a[j][k] -= factor * a[i][k];
            }
        }
        return abs(res);
    }
    
    int countSpanTree(int n, vector<vector<int>>& edges)
    {
        // Build Laplacian with double
        vector<vector<double>> lap(n, vector<double>(n, 0.0));
        vector<int> deg(n, 0);
        for (auto& e : edges)
        {
            int u = e[0], v = e[1];
            lap[u][v] = -1.0;
            lap[v][u] = -1.0;
            deg[u]++;
            deg[v]++;
        }
        for (int i = 0; i < n; i++)
            lap[i][i] = deg[i];
        // Submatrix
        vector<vector<double>> sub(n-1, vector<double>(n-1, 0.0));
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-1; j++)
                sub[i][j] = lap[i][j];
        double result = det(sub, n-1);
        return (int)(result + 0.5);  // Round to nearest int
    }
};
