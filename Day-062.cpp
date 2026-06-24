/*
Problem name : << Rat Maze With Multiple Jumps >>

Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1] is not 0.
Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path exists, return [[-1]].
Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.

Example:
Input: mat[][] = [[2, 1, 0, 0], [3, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
Output: [[1, 0, 0, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]
Explanation: 
The rat starts from cell (0, 0) which contains value 2, so it can jump at most 2 steps either right or downward. 
Steps:
-> Moves downward to (1, 0) which contains value 3.
-> Jumps 3 steps right to reach (1, 3).
-> Moves downward through (2, 3) and reaches the destination cell (3, 3).

Input: mat[][] = [[2, 1, 0, 0], [2, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
Output: [[-1]]
Explanation: The rat starts at (0, 0) with value 2, but every possible path from there eventually reaches a cell containing 0. Since no sequence of jumps can reach the destination cell (3, 3), no valid path exists and the output is [[-1]].
*/

// =========================================================== >> Solution
class Solution
{
    public:
    bool solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &ans, vector<vector<int>> &dp)
    {
        int n = mat.size();
        // For out of bounds
        if(i >= n || j >= n)
            return false;
        // Destination reached
        if((i == n - 1) && (j == n - 1))
        {
            ans[i][j] = 1;
            return true;
        }
        // If current cell is blocked
        if(mat[i][j] == 0)
            return false;
        // Memoization --> if already calculated = return stored result
        if(dp[i][j] != -1)
            return dp[i][j];
        // Make current cell as part of solution path
        ans[i][j] = 1;
        int jump = mat[i][j];
        // Shortest jumps
        for(int step = 1; step <= jump ; step++)
        {
            if(solve(i, j + step, mat, ans, dp))
                return dp[i][j] = 1;
            if(solve(i + step, j, mat, ans, dp))
                return dp[i][j] = 1;
        }
        // Backtrack --> unmark cell if it leads to dead end
        ans[i][j] = 0;
        return dp[i][j] = 0;
    }
    
    vector<vector<int>> shortestDist(vector<vector<int>>& mat)
    {
        int n = mat.size();
        // Special case of 1x1 matrix
        if(n == 1)
            return {{1}};
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if(mat[0][0] == 0)
            return {{-1}};
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if(!solve(0, 0, mat, ans, dp))
            return {{-1}};
        return ans;
    }
};
