/*
Problem name : << Largest Unblocked Submatrix >>

You are given integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell in an n × m grid.
Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area in the grid.
Note: No two blocked cells are in the same row or the same column.

Examples:
Input: n = 2, m = 2, k = 1, arr[][] = [[2, 2]]
Output: 1
Explanation: Since only (1,1) cell is free from the enemy hence answer is 1.

Input: n = 3, m = 3, k = 1, arr[][] = [[3, 3]]
Output: 4
Explanation: The cells (1,1), (1,2), (2,1) and (2,2) are free hence answer is 4.
*/

// ================================================= >> Solution
class Solution
{
    public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr)
    {
        vector<int> rows;
        vector<int> cols;
        // Store blocked rows and columns
        for(int i = 0; i < k ; i++)
        {
            rows.push_back(arr[i][0]);
            cols.push_back(arr[i][1]);
        }
        // Add boundaries for rows
        rows.push_back(0);
        rows.push_back(n + 1);
        // Add boundaries for columns
        cols.push_back(0);
        cols.push_back(m + 1);
        // Sort rows and columns
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int rgap = 0;
        int cgap = 0;
        // Finding largest gap
        for(int i = 1 ; i < rows.size() ; i++)
            rgap = max(rgap, rows[i] - rows[i - 1] - 1);
        for(int i = 1 ; i < cols.size() ; i++)
            cgap = max(cgap, cols[i] - cols[i - 1] - 1);
        return rgap * cgap;
    }
};
