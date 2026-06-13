/*
Problem name : << Binary Strings with Equal Sum of Two Halves >>

Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits. 
Note: Since the anwer can be very large, so return the answer modulo 1e9+7.

Examples:
Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 2*n, the sequences are 0101, 0110, 1010, 1001, 0000 and 1111.

Input: n = 1
Output: 2
Explanation: There are 2 sequence of length 2*n, the sequence are 00 and 11. 
*/

// ================================================================> Solution
class Solution
{
    int mod = 1e9 + 7;
    public:
    long long power(long long a, long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b & 1)
                ans = (ans * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return ans;
    }
    
    int computeValue(int n)
    {
        long long f1 = 1;
        long long f2 = 1;
        // Calculate (2n)!
        for(int i = 1; i <= (2*n) ; i++)
            f1 = (f1 * i) % mod;
        // Calculate n!
        for(int i = 1; i <= n; i++)
            f2 = (f2 * i) % mod;
        long long den = (f2 * f2) % mod;
        long long ans = (f1 * power(den, mod - 2)) % mod;
        return ans;
    }
};
