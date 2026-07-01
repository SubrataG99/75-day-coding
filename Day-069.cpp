/*
Problem name : << Max Subarray Sum by Removing At Most One >>

Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.
Note: After skipping the element, the subarray must still be non-empty.

Examples:
Input: arr[] = [1, 2, 3, -4, 5]
Output: 11
Explanation: We can get maximum sum subarray by skipping -4.

Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 9
Explanation: We can get maximum sum subarray by skipping -2 as [4,-1,1,5] sums to 9, which is the maximum achievable sum.
*/

// ======================================================== >> Solution

class Solution
{
    public:
    int maxSumSubarray(vector<int>& arr)
    {
        int n = arr.size();
        // noDel -> Maximum subarray sum ending at current index without deletion
        int noDel = arr[0];
        // oneDel -> Maximum subarray sum ending at current index with at most one deletion
        int oneDel = 0;
        int ans = arr[0];
        for(int i = 1 ; i < n ; i++)
        {
            // Either delete current element OR extend previous deleted subarray
            oneDel = max(noDel, arr[i] + oneDel);
            // Standard Kadane transition
            noDel = max(arr[i], arr[i] + noDel);
            // Update answer
            ans = max(ans, max(noDel, oneDel));
        }
        return ans;
    }
};
