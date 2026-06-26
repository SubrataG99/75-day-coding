/*
Problem name : << Count Matching Subsequences >>

Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.
Return the total count modulo 1e9+7.

Examples :
Input: s1 = "geeksforgeeks", s2 = "gks"
Output: 4
Explanation: We can pick characters from s1 as a subsequence from indices [0, 3, 4], [0, 3, 12], [0, 11, 12] and [8, 11, 12]. So total 4 subsequences of s1 that are equal to s2.

Input: s1 = "problemoftheday", s2 = "geek"
Output: 0
Explanation: No subsequence of string s1 is equal to string s2.
*/

// ================================================================= >> Solution
class Solution
{
    public:
    int countWays(string &s1, string &s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int mod = 1e9 + 7;
        vector<int> dp(n2 + 1, 0);
        // Empty string can always be formed
        dp[0] = 1;
        for(int i = 1 ; i <= n1 ; i++)
            for(int j = n2 ; j >= 1 ; j--)
            // If current character match, include or exclude current character
                if(s1[i - 1] == s2[j - 1])
                    dp[j] = (dp[j] + dp[j - 1]) % mod;
        return dp[n2];
    }
};
