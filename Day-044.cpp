/*
Problem name : << Non-Attacking Black and White Knights >>

Given two integers n and m representing the dimensions of a chessboard, find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.
Note:
The knights have to be placed on different squares.
A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
The knights attack each other if one can reach the other in one move.

Examples:
Input: n = 2, m = 2
Output: 12 
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

Input: n = 2, m = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
*/

// ======================================================> Solution
class Solution
{
    public:
    int numOfWays(int n, int m)
    {
        // Possible moves
        int x[]{-2, -1, 1, 2};
        int y[]{1, 2, 2, 1}; 
        // Total moves possible in board
        long long total = (n * m) * ((n * m) - 1);
        long long ways = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                for(int k = 0; k < 4 ; k++)
                {
                    int xMove = i + x[k];
                    int yMove = j + y[k];
                    // Only the possible ones
                    if((xMove >= 0) && (xMove < m) && (yMove >= 0) && (yMove < n))
                        ways = ways + 2;
                }
            }
        }
        // Take only the non-attacking moves
        return (total - ways);
    }
};
