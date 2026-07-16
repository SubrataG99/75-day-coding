/*
Problem name : << Numbers with Given Digit Sum >>

Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.
An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
If there exist no n digit number with sum of digits equal to given sum, return -1.

Examples :
Input: n = 2, sum = 2
Output: 2
Explaination: The valid 2-digit numbers whose digits sum to 2 are 11 and 20.

Input: n = 1, sum = 10
Output: -1
Explaination: A single-digit number can only have a digit sum between 0 and 9.

Input: n = 2, sum = 10
Output: 9
Explaination: The 2-digit numbers whose digits add up to 10 are: 19, 28, 37, 46, 55, 64, 73, 82, 91.
*/

// ======================================================== >> Solution
class Solution
{
    public:
    int countWays(int n, int sum)
    {
        if(sum > 9 * n)
            return -1;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for(int len = 1 ; len <= n ; len++)
            for(int s = 0 ; s <= sum ; s++)
                for(int digit = 0 ; digit < 10 ; digit++)
                    if(s >= digit)
                        dp[len][s] = dp[len][s] + dp[len - 1][s - digit];
        int ans = 0;
        for(int digit = 1 ; digit < 10 ; digit++)
            if(sum >= digit)
                ans = ans + dp[n - 1][sum - digit];
        return (ans == 0) ? -1 : ans;
    }
};
