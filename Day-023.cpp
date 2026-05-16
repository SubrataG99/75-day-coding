/*
Problem name : << Not a subset sum >>

Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:
Input: arr[] = [3, 1, 2]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.

Input: arr[] = [3, 10, 9, 6, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
*/

// ========================================================= >> Solution
class Solution
{
    public:
    int findSmallest(vector<int> &arr)
    {
        // IF empty array, it should be 1 as smallest positive number
        if(arr.size() == 0)
            return 1;
        int ans = 1;
        // Sort the array to get the subset
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() ; i++)
            if(ans >= arr[i])
                ans = ans + arr[i];
        return ans;
    }
};
