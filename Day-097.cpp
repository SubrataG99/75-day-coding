/*
Problem name : << Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets such that each subset contains consecutive numbers. >>

Examples:
Input: arr[] = [100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59]
Output: 3
Explanation: [5, 6, 7], [56, 57, 58, 59], [100, 101, 102, 103] are 3 subsequences in which numbers are consecutive.

Input: arr[] = [10, 100, 105]
Output: 3
Explanation: [10], [100] and [105] are 3 subset in which numbers are consecutive.
*/

// ================================================== >> Solution
class Solution
{
    public:
    int minSubsets(vector<int>& arr)
    {
        unordered_set<int> s(arr.begin(), arr.end());
        int count = 0;
        for(int x : arr)
        {
            // Check for start of new subset
            if(s.find(x - 1) == s.end())
                count++;
        }
        return count;
    }
};
