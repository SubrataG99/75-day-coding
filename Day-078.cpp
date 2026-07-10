/*
Problem name : << Ways to Express as Sum of Consecutives >>

Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Examples:
Input: n = 10
Output: 1
Explanation: There is only one way, 10 = 1+2+3+4.
Input: n = 15
Output: 3
Explanation: There are 3 ways, (15 = 1+2+3+4+5), (15 = 4+5+6) and (15 = 7+8).
*/

// ==================================================== >> Solution
class Solution
{
    public:
    int getCount(int n)
    {
        int count = 0;
        // k represents the number of elements in our consecutive sequence, we need at least 2 numbers, so we start checking from k = 2.
        for(long long k = 2 ;  ; k++)
        {
            // baseSum is the sum of the first (k-1) numbers: 1 + 2 + ... + (k-1)
            long long base = (k * (k - 1) / 2);
            // if the minimum possible sum of k elements is greater than or equal to n, no valid sequence of length k or greater can exist.
            if(base >= n)
                break;
            // if (n - baseSum) can be divided equally among the k elements, it means a valid starting integer 'a' exists.
            if((n - base) % k == 0)
                count++;
        }
        return count;
    }
};
