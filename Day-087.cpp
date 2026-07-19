/*
Problem name : << Mountain Subarray Queries >>

Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].
Elements of a Mountain subarray are first non-decreasing and then non-increasing.
A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.

Examples:
Input: arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, false]
Explanation: For query [0, 2], the subarray is [2, 3, 2]. The elements first increase and then decrease, so it forms a mountain.
For query [1, 3], the subarray is [3, 2, 4]. The elements decrease and then increase, so it does not form a mountain.

Input: arr[] = [2, 2, 2, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, true]
Explanation: All subarrays of the given array are mountain.
*/

// ==========================================================>> Solution
class Solution
{
    public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        // dec[i] stores the farthest index reachable from i while maintaining a non-decreasing sequence.
        vector<int> dec(n);
        dec[n - 1] = n - 1;
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            if(arr[i] <= arr[i + 1])
                dec[i] = dec[i + 1];
            else
                dec[i] = i;
        }
        // inc[i] stores the leftmost index reachable from i while maintaining a non-increasing sequence.
        vector<int> inc(n);
        inc[0] = 0;
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] <= arr[i - 1])
                inc[i] = inc[i - 1];
            else
                inc[i] = i;
        }
        vector<bool> ans;
        for(auto &query : queries)
        {
            int l = query[0];
            int r = query[1];
            ans.push_back(dec[l] >= inc[r]);
        }
        return ans;
    }
};
