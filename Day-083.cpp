/*
Problem name : << Longest Bitonic Subarray >>

Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic subarray.
A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists and index k (where i <= k <= j) such that:
arr[i] <= arr[i+1] <= . . . <= arr[k] 
arr[k] >= arr[k+1] >= . . . >= arr[j]

Examples: 
Input: arr[] = [12, 4, 78, 90, 45, 23]
Output: 5
Explanation: The longest bitonic subarray is [4, 78, 90, 45, 23], it starts increasing at 4, peaks at 90, and decreases to 23, giving length of 5.

Input: arr[] = [10, 20, 30, 40]
Output: 4
Explanation: The array [10, 20, 30, 40] is striclty increasing with no decreasing part, so longest bitonic subarray is the entire array itself, giving a length of 4.

Input: arr[] = [10, 10, 10, 10]
Output: 4
*/

// ======================================================= >> Solution
class Solution
{
    public:
    int bitonic(vector<int> &arr)
    {
        int count = 1;
        int n = arr.size();
        if(n == 0)
            return 0;
        int start = 0;
        int next = 0;
        int j = 0;
        while(j < (n - 1))
        {
            while(j < n - 1 && arr[j] <= arr[j + 1])
                j++;
            while(j < n - 1 && arr[j] >= arr[j + 1])
            {
                if(j < n - 1 && arr[j] > arr[j + 1])
                    next = j + 1;
                j++;
            }
            count = max(count, j - start + 1);
            start = next;
        }
        return count;
    }
};
