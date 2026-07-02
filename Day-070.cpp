/*
Problem name : << Check Subset sum divisible by k >>

Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the given array is divisible by k otherwise, return false.

Examples:
Input: arr[] = [3, 1, 7, 5] , k = 6
Output: true
Explanation: If we take the subset {7, 5} then sum will be 12 which is divisible by 6.

Input: arr[] = [1, 2, 6] , k = 5
Output: false
Explanation: All possible subsets of the given set are {1}, {2}, {6}, {1, 2}, {2, 6}, {1, 6} and {1, 2, 6}. There is no subset whose sum is divisible by 5.
*/

// ======================================================= >> Solution
class Solution
{
    public:
    bool divisibleByK(vector<int>& arr, int k)
    {
        int n = arr.size();
        if (n > k)
            return true;
        vector<bool> dp(k, false);
        for(int i = 0 ; i < n ; i++)
        {
            // Subset with divisible sum found
            if (dp[0])
                return true;
            // New remainders formed using arr[i]
            vector<bool> temp(k, false);
            // Extend existing remainders
            for(int j = 0 ; j < k ; j++)
                if (dp[j] && !dp[(j + arr[i]) % k])
                    temp[(j + arr[i]) % k] = true;
            // Update dp with new remainders
            for(int j = 0 ; j < k ; j++)
                if (temp[j])
                    dp[j] = true;
            // Single element subset
            dp[arr[i] % k] = true;
        }
        return dp[0];
    }
};
