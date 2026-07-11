/*
Problem name : << Longest Possible Route in a Matrix with Hurdles >>

Given a binary matrix mat[][] of size n × m containing values 0 and 1, and four integers xs, ys, xd, and yd representing the source cell (xs, ys) and destination cell (xd, yd), find the length of the longest possible path from the source cell to the destination cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

1 represents a traversable cell.
0 represents a blocked cell that cannot be visited.
A cell can be visited at most once in a path.
If the destination cannot be reached from the source, return -1.

Examples:
Input: mat[][] = [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 0, 1, 1, 0, 1],[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]], xs = 0, ys = 0, xd = 1, yd = 7
Output: 24 
Explanation: The longest valid path from (0, 0) to (1, 7) without revisiting any cell has length 24. 

Input: mat[][] = [[1, 0, 0, 1, 0],[0, 0, 0, 1, 0],[0, 1, 1, 0, 0]], xs = 0, ys = 3, xd = 2, yd = 2
Output: -1
Explanation: The destination cell (2, 2) cannot be reached from the source cell (0, 3), so the answer is -1.
*/

// ===================================================== >> Solution
class Solution
{
    public:
    int dfs (vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int x, int y)
    {
        int m = mat.size();
        int n = mat[0].size();
        // If destination is reached
        if( i == x && j == y)
            return 0;
        // Cell is invalid, blocked or visited already
        if(i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 0 || visited[i][j])
            return -1;
            // Mark current cell as visited
        visited[i][j] = true;
        int mpath = -1;
        // possible moves : U, D, L, R
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        for(int k = 0 ; k < 4 ; k++)
        {
            int ni = i + r[k];
            int nj = j + c[k];
            int plen = dfs(mat, visited, ni, nj, x, y);
            if(plen != -1)
                mpath = max(mpath, 1 + plen);
        }
        // Backtrack
        visited[i][j] = false;
        return mpath;
    }
    
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd)
    {
        int m = mat.size();
        int n = mat[0].size();
        // Check if source or destination is blocked
        if(mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        return dfs(mat, visit, xs, ys, xd, yd);
    }
};
