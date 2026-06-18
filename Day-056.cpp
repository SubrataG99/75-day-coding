/*
Problem name : << Coverage of all Zeros in a Binary Matrix >>

Given a binary matrix mat[][] containing only 0s and 1s, find the total coverage of all 0's. The coverage of a particular 0 cell is defined by checking 1's in its four directions (left, right, up, and down). For each direction, if there is at least one 1 anywhere between the 0 and the boundary of the matrix, the coverage increases by one.
Return the sum of the coverage values for all 0 cells in the matrix.

Examples:
Input : [[1, 1, 1, 0]
          [1, 0, 0, 1]]
Output : 8
Explanation: Coverage of first zero is 2. Coverages of other two zeros is 3 Total coverage = 2 + 3 + 3 = 8

Input: matrix = [[0, 1, 0],
               [0, 1, 1],
               [0, 0, 0]]
Output: 6
Explanation: Total Coverage is 1 + 2 + 1 + 0 + 1 + 1 = 6   

Input: matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage. There fore answer for this test case is 5.
*/

// ============================================================== >> Solution

class Solution
{
    public:
    int findCoverage(vector<vector<int>>& mat)
    {
        int cov = 0;
        int r = mat.size();
        int c = mat[0].size();
        for(int i = 0 ; i < r ; i++)
        {
            bool is1 = false;
            // Left to right traversal
            for(int j = 0 ; j < c ; j++)
            {
                if(mat[i][j] == 1)
                    is1 = true;
                else if(is1)
                    cov++;
            }
            is1 = false;
            // Right to Left traversal
            for(int j = c-1 ; j >=0 ; j--)
            {
                if(mat[i][j] == 1)
                    is1 = true;
                else if(is1)
                    cov++;
            }
        }
        for(int j = 0 ; j < c ; j++)
        {
            bool is1 = false;
            // Up to Down traversal
            for(int i = 0 ; i < r ; i++)
            {
                if(mat[i][j] == 1)
                    is1 = true;
                else if(is1)
                    cov++;
            }
            is1 = false;
            // Down to Up traversal
            for(int i = r-1 ; i >= 0 ; i--)
            {
                if(mat[i][j] == 1)
                    is1 = true;
                else if(is1)
                    cov++;
            }
        }
        return cov;
    }
};
