/*
Problem name : << Cut rope to maximise product >>

Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.

Examples:
Input: n = 2
Output: 1
Explanation: Since 1 cut is mandatory. Maximum obtainable product is 1 * 1 = 1.

Input: n = 5
Output: 6
Explanation: Maximum obtainable product is 2 * 3 = 6.
*/

// ===================================================== >> Solution
class Solution
{
    public:
    int power(int b, int p)
    {
        int res = 1;
        while(p)
        {
            if(p & 1)
                res = res * b;
            b = b * b;
            p = p >> 1;
        }
        return res;
    }
    
    int maxProduct(int n)
    {
        // Edge case: for small values
        if((n == 2) || (n == 3))
            return (n-1);
        // Count how many 3s we can take
        int c3 = n/3;
        int rem = n % 3;
        if(rem == 1)
        {
            c3 = c3 - 1;
            rem = 4;
        }
        int prod = power(3, c3);
        // Handle remaining part (0, 2 or 4)
        if((rem == 2) || (rem == 4))
            prod = prod * rem;
        return prod;
    }
};
