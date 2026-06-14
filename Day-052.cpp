/*
Problem name : << Exit Point in a Matrix >>

Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0) and initially move in the left-to-right direction (i.e., towards the right).
While traversing the matrix, follow these rules:
If the current cell contains 0, continue moving in the same direction.
If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.
You continue this process until you move outside the boundaries of the matrix. Your task is to determine the coordinates (row and column index) of the cell from which you exit the matrix.

Examples:
Input: mat[][] = [[0, 1, 0],
               [0, 1, 1], 
               [0, 0, 0]]
Output: [1, 0]
Explanation: 
From the image we can see that, enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed. Hence, exit point reached at [1, 0].

Input: mat[][] = [[0, 0]]
Output: [0, 1]
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell [0, 1].
*/

// ==========================================================================> Solution
class Solution
{
    public:
    vector<int> exitPoint(vector<vector<int>>& mat)
    {
        // 0 = right ; 1 = down ; 2 = left ; 3 = up
        int dir = 0;
        // mat.size() --> rows
        int row = mat.size();
        // mat[0].size() --> columns
        int col = mat[0].size();
        int r = 0;
        int c = 0;
        while((r >= 0) && (r < row) && (c >= 0) && (c < col))
        {
            dir = (dir + mat[r][c]) % 4;
            // Change the 1 into 0 if encountered
            if(mat[r][c] == 1)
                mat[r][c] = 0;
            // Rotate based on direction
            if(dir == 0)
                c++;
            else if(dir == 1)
                r++;
            else if(dir == 2)
                c--;
            else if(dir == 3)
                r--;
        }
        // Now need to change the last move as it crossed the boundary
        if(dir == 0)
            c--;
        else if(dir == 1)
            r--;
        else if(dir == 2)
            c++;
        else if(dir == 3)
            r++;
        // Add the final values in a vector
        vector<int> coord{r, c};
        return coord;
    }
};
