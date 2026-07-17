/*
Problem name : << Max Absolute Diff of Two Subarrays >>

Given an array of integers arr[], find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.

Examples :
Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 12
Explanation: Two subarrays are [-2, -3] and [4, -1, -2, 1, 5]

Input: arr[] = [2, -1, -2, 1, -4, 2, 8]
Output: 16
Explanation: Two subarrays are [-1, -2, 1, -4] and [2, 8]
*/

// =====================================================>> Solution
class Solution
{
    public:
    // To get arr[0] to arr[i]
    vector<int> buildLeft(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n);
        int curr = arr[0];
        int best = arr[0];
        left[0] = best;
        for(int i = 1 ; i < n ; i++)
        {
            // Apply Kadane's algorithm
            curr = max(arr[i], curr + arr[i]);
            best = max(best, curr);
            left[i] = best;
        }
        return left;
    }
    
    // To get arr[i + 1] to arr[n - 1]
    vector<int> buildRight(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> right(n);
        int curr = arr[n - 1];
        int best = arr[n - 1];
        right[n - 1] = best;
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            // Apply Kadane's algorithm
            curr = max(arr[i], curr + arr[i]);
            best = max(best, curr);
            right[i] = best;
        }
        return right;
    }
    
    int maxDiffSubArrays(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> leftMax = buildLeft(arr);
        vector<int> rightMax = buildRight(arr);
        vector<int> inv(arr);
        for(int &x : inv)
            x = -x;
        vector<int> leftMin = buildLeft(inv);
        vector<int> rightMin = buildRight(inv);
        for(int &x : leftMin)
            x = -x;
        for(int &x : rightMin)
            x = -x;
        int res = INT_MIN;
        for(int i = 0; i < n - 1 ; i++)
        {
            // Max on left + Min on right
            int op1 = abs(leftMax[i] - rightMin[i + 1]);
            // Min on left + Max on right
            int op2 = abs(leftMin[i] - rightMax[i + 1]);
            // Update answer
            res = max(res, max(op1, op2));
        }
        return res;
    }
};
