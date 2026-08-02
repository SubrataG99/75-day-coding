/*
Problem name : << Sequences where Adjacent Divide >>

Given two positive integer n and m. Find the number of arrays of size n that can be formed such that:
Each element is in the range [1, m].
All adjacent are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai+1 divides Ai.

Examples:
Input: n = 3, m = 3
Output : 17
Explanation: The possible arrays are [1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 1], [1, 2, 2], [1, 3, 1], [1, 3, 3], [2, 1, 1], [2, 1, 2], [2, 1, 3], [2, 2, 1], [2, 2, 2], [3, 1, 1], [3, 1, 2], [3, 1, 3], [3, 3, 1] and [3, 3, 3].

Input: n = 1, m = 10 
Output: 10
Explanation: The possible arrays are [1], [2], [3], [4], [5], [6], [7], [8], [9] and [10].
*/

// ================================================================= >> Solution

class Solution
{
    public:
    int MOD = 1e9 + 7;
    int count(int n, int m)
    {
        // dp[len][val] = Number of valid arrays of length len ending with value val
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // factors[x]  -> all factors of x
        vector<vector<int>> factors(m + 1);
        // multiples[x] -> all multiples of x
        vector<vector<int>> multiples(m + 1);
        // precompute factors and multiples
        for (int i = 1 ; i <= m ; i++)
        {
            for (int j = i ; j <= m ; j = j + i)
            {
                factors[j].push_back(i);
                if ( j != i)
                    multiples[i].push_back(j);
            }
        }
        // Base case : Arrays of length 1
        for (int val = 1 ; val <= m ; val++)
            dp[1][val] = 1;
        // Build DP table
        for (int len = 2 ; len <= n ; len++)
        {
            for (int curr = 1 ; curr <= m ; curr++)
            {
                // Add all factors
                for (int prev : factors[curr])
                    dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % MOD;
                // Add all multiples
                for (int prev : multiples[curr])
                    dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % MOD;
            }
        }
        int ans = 0;
        for (int val = 1 ; val <= m ; val++)
            ans = (ans + dp[n][val]) % MOD;
        return ans;
    }
};
