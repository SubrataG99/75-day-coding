/*
Problem name : << Max Product Subset >>

Given an array arr[], find and return the maximum product possible with the subset of elements present in the array.
Note:
The maximum product can be of a single element also.
Since the product can be large, return it modulo 109 + 7.

Examples:
Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24

Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0

Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
*/

// ==============================================>> Solution
class Solution
{
    public:
    int findMaxProduct(vector<int>& arr)
    {
        // Return only one element present as that will be max product
        if(arr.size() == 1)
            return arr[0];
        long long prod = 1;
        int mod = 1e9 + 7;
        int minNeg = INT_MIN;
        int minId = -1;
        int neg = 0;
        int zero = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            // Track count of zeroes
            if(arr[i] == 0)
                zero++;
            // Track Negative numbers
            else if(arr[i] < 0)
            {
                neg++;
                // Get the negative number with lowest absolute value
                if((minId == -1) || (arr[i] > minNeg))
                {
                    minNeg = arr[i];
                    minId = i;
                }
            }
        }
        // If all zeroes in array
        if(zero == arr.size())
            return 0;
        // If only 1 negative and all zeroes
        if((neg == 1) && (zero == arr.size() - 1))
            return 0;
        // For normal numbers
        for(int i = 0; i < arr.size() ; i++)
        {
            // Ignore for zeroes
            if(arr[i] == 0)
                continue;
            // Ignore if odd number of negatives and for lowest abs(negative)
            if((neg % 2 == 1) && (i == minId))
                continue;
            // return final product
            prod = ((prod * arr[i]) % mod + mod) % mod;
        }
        return prod;
    }
};
