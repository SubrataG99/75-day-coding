/*
Problem Name : << Count Sorted Digit Groupings >>
Given a string s consisting of digits, you can split it into contiguous substrings (sub-groups). For example, the string "112" can be split as: ["1","1","2"], ["11","2"], ["1","12"], and ["112"]. A grouping is considered valid if the sums of digits of the sub-groups form a non-decreasing sequence from left to right. Determine the total number of such valid groupings for the given string.

Examples:
Input: s = "1119"
Output: 7
Explanation: 
One valid grouping is ["1", "11", "9"].
The sum of digits of the first sub-group ("1") is 1,
for the second sub-group ("11"), it is 2,
and for the third sub-group ("9"), it is 9.
Since the sums are in non-decreasing order (1 ≤ 2 ≤ 9), this is a valid grouping.
The other valid groupings are:
["1", "119"], ["1", "1", "19"], ["1", "1", "1", "9"], ["11", "19"], ["111", "9"], and ["1119"].
Thus, the total number of valid groupings is 7.

Input: s = "12"
Output: 2
Explanation: 
["1","2"] and ["12"] are two valid groupings.
*/

// =============================================================>> Solution
class Solution
{
    public:
    int validGroups(string &s)
    {
        int n = s.length();
        // For max sum possible
        int maxSum = n * 9;
        vector<vector <int>> dp(n+1, vector<int>(maxSum + 1, 0));
        for(int prev = 0; prev <= maxSum ; prev++)
            dp[n][prev] = 1;
        for(int i = n - 1 ; i >= 0; i--)
            for(int prev = 0 ; prev <= maxSum ; prev++)
            {
                int currSum = 0;
                for(int j = i ; j < n ; j++)
                {
                    currSum = currSum + s[j] - '0';
                    if(currSum >= prev)
                        dp[i][prev] += dp[j + 1][currSum];
                }
            }
        return dp[0][0];
    }
};
