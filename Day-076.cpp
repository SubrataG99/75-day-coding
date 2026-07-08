/*
Problem name : << Towers Reaching Both Stations >>

Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control stations monitor the network:
Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.
A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.
Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.

Examples:
Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
Output: 7
Explanation: 
(0, 4) & (4, 0) are part of both P & Q 
(1, 3) reaches P using (1,3)->(0,3) and Q using (1,3)->(1,4)
(1, 4) reaches P using (1,4)->(1,3)->(1,2)->(0,2) and it is on Q
(2, 2) reaches P using (2,2)->(2,1)->(2,0) and Q using (2,2)->(2,3)->(2,4)
(3, 0) is on P and reaches Q using (3,0)->(4,0)
(3, 1) reaches P using (3,1)->(3,0) and Q using (3,1)->(4,1)

Input: mat[][] = [[2, 2], [2, 2]]
Output: 4
Explanation: In the following example, all cells allow signals to propagate to both the stations.
*/

// ================================================= >> Solution
class Solution
{
    public:
    // direction vector for U, D, L, R
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    
    void bfs(vector<vector<int>> &strength, int n, int m, queue<pair<int, int>> &q, vector<vector<bool>> &reach)
    {
        while(!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++)
            {
                int newrow = row + dx[k];
                int newcol = col + dy[k];
                if(isValid(newrow, newcol, n, m) && !reach[newrow][newcol] && strength[newrow][newcol] >= strength[row][col])
                {
                    reach[newrow][newcol] = true;
                    q.push({newrow, newcol});
                }
            }
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> stP, stQ;
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        for(int j = 0 ; j < m ; j++)
        {
            stP.push({0, j});
            reachP[0][j] = true;
            stQ.push({n - 1, j});
            reachQ[n - 1][j] = true;
        }
        for(int i = 0 ; i < n ; i++)
        {
            stP.push({i, 0});
            reachP[i][0] = true;
            stQ.push({i, m - 1});
            reachQ[i][m - 1] = true;
        }
        bfs(mat, n, m, stP, reachP);
        bfs(mat, n, m, stQ, reachQ);
        int count = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(reachP[i][j] && reachQ[i][j])
                    count++;
        return count;
    }
};
