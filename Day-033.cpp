/*
Problem name : << Minimum Toggle to Partition >>

Given an array arr[] containing only 0 and 1. Find the minimum toggles (switch from 0 to 1 or vice-versa) required such the array become partitioned, i.e., it has first 0s then 1s.

Examples:
Input: arr = [1, 0, 1, 1, 0]
Output: 2
Explaination: The changed array will be [0, 0, 1, 1, 1]. So the number of toggles here required is 2.

Input: arr = [0, 1, 0, 0, 1, 1, 1]
Output: 1
Explaination: The changed array will be [0, 0, 0, 0, 1, 1, 1]. Required toggles are 1.
*/

// ========================================================>> Solution
class Solution
{
    public:
    int minToggle(vector<int>& arr)
    {
        int one = 0;
        int trip = 0;
        for(int i : arr)
        {
            if(i == 1)
                one++;
            else
                trip = min(trip+1, one);
        }
        return trip;
    }
};
