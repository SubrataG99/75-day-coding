/*
Problem name : << Pairs with certain difference >>
Given an array of integers and a number k, the task is the find maximum pair sum with the following conditions on the pairs.
Pair difference should be less than k.
Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
Sum of p pairs means sum of 2p elements in the result.
If no valid pairs can be formed, return 0.

Examples:
Input: arr[] = [3, 5, 10, 15, 17, 12, 9], K = 4
Output: 62
Explanation :
The valid disjoint pairs with difference less than K are:
(3, 5), (10, 12), (15, 17)
The maximum sum obtained from these pairs is:
3 + 5 + 10 + 12 + 15 + 17 = 62
An alternative pairing could be:
(3, 5), (9, 12), (15, 17)
However, this combination results in a smaller total sum, so it is not optimal.

Input: arr[] = [5, 15, 10, 300], k = 12
Output: 25
Explanation: 
The valid disjoint pairs with difference less than k are:
(5, 10)
The maximum sum obtained from these pairs is:
5 + 10 = 15
An alternative pairing could be:
(10, 15)
However, this combination results in a larger total sum:
10 + 15 = 25. So this pairing is optimal.
*/

// =============================================>> Solution
class Solution
{
    public:
    int sumDiffPairs(vector<int>& arr, int k)
    {
        int res = 0;
        // Sort to get the array for easy difference calculation
        sort(arr.begin(), arr.end());
        for(int i = arr.size() - 1; i > 0 ; --i)
        {
            // If the condition is true
            if(arr[i] - arr[i - 1] < k)
            {
                res = res + arr[i] + arr[i - 1];
                // Skip the next elemet of the array
                // else check the next element with its adjacent
                --i;
            }
        }
        return res;
    }
};
