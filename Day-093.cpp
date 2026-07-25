/*
Problem name : << Max Sum Square Sub-Matrix of Size k >>

Given an n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.

Examples:
Input: k = 3, mat[][] = [[1, 2, -1, 4], [-8, -3, 4, 2], [3, 8, 10, -8], [-4, -1, 1, 7]]
Output: 20
Explanation: The 3 × 3 sub-grid [[-3, 4, 2], [8, 10, -8], [-1, 1, 7]] highlighted in red has the maximum sum of 20.

Input: k = 1, mat[][] = [[4]]
Output: 4
Explanation: Only one 1×1 sub-grid exists with sum 4.
*/

// ============================================================= >> Solution
class Solution
{
    public:
    int maximumSum(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        int sms = INT_MIN;
        vector<int> colSum(n, 0);
        for(int i = 0 ; i < n ; i++)
        {
            // Update column sums with new row entering and old row leaving window
            for(int j = 0 ; j < n ; j++)
            {
                colSum[j] = colSum[j] + mat[i][j];
                if(i >= k)
                    colSum[j] = colSum[j] - mat[i - k][j];
            }
            // Slide horizontal window of size k over colSum
            if(i >= k - 1)
            {
                int winSum = 0;
                for(int j = 0 ; j < n ; j++)
                {
                    winSum = winSum + colSum[j];
                    if(j >= k)
                        winSum = winSum - colSum[j - k];
                    if(j >= k - 1)
                        sms = max(sms, winSum);
                }
            }
        }
        return sms;
    }
};
