/*
Problem name : << k Times Appearing Adjacent Two 1's >>

Given two integers n and k, count the number of binary strings of length n where adjacent 1 appear k times.
Since the answer can be huge, return it modulo 109+7.

Examples:
Input: n = 3, k = 2
Output: 1
Explanation: Possible string is "111" where 2 adjacent 1 appear.

Input: n = 5, k = 2
Output: 6
Explanation: Possible strings are "00111", "10111", "01110", "11100", "11101" and "11011".
*/

// ===================================================== >> Solution
class Solution
{
    public:
    int countStrings(int n, int k)
    {
        int Max = 1001;
        int mod = 1e9 + 7;
        // dp[i][j][0] -> number of binary strings of length i
        //               having j adjacent 1's and ending with 0
        //
        // dp[i][j][1] -> number of binary strings of length i
        //               having j adjacent 1's and ending with 1
        int dp[Max][Max][2];
        for(int i = 0 ; i < n + 1 ; i++)
            for(int j = 0 ; j < k + 1 ; j++)
                for(int l = 0 ; l < 2 ; l++)
                    dp[i][j][l] = 0;
        // Base Case:
        // For string length = 1, there are no adjacent 1's
        // Possible strings: "0", "1"
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        for(int i = 2 ; i <= n; i++)
            // Adjacent 1's count can be at most i-1
            for(int j = 0 ; j < i ; j++)
            {
                // Case 1: Append '0'
                // We can append '0' to both strings ending in 0 and 1
                dp[i][j][0] = (dp[i - 1][j][0] % mod + dp[i - 1][j][1] % mod) % mod;
                // Case 2: Append '1'
                // If previous was '0', no new adjacent pair is formed
                dp[i][j][1] = dp[i - 1][j][0] % mod;
                // If previous was '1', we form one new adjacent pair
                if (j - 1 >= 0)
                    dp[i][j][1] = (dp[i][j][1] % mod + dp[i - 1][j - 1][1] % mod) % mod;
            }
        // Final result = strings ending with 0 + strings ending with 1
        return (dp[n][k][0] % mod + dp[n][k][1] % mod) % mod;
    }
};
