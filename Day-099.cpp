/*
Problem name : << Subsets with Products of Distinct Primes >>

Given an integer array arr[], count the number of different subsets whose product can be represented as a product of one or more distinct prime numbers.  Two subsets are considered different if the set of chosen array indexes are not same.
Return the count modulo 109 + 7.

Examples:
Input: arr[] = [1, 2, 3, 4]
Output: 6
Explanation: 
The subsets are:
[2], product = 2 = 2
[3], product = 3 = 3
[1, 2], product = 2 = 2
[1, 3], product = 3 = 3
[2, 3], product = 6 = 2 × 3
[1, 2, 3], product = 6 = 2 × 3
All these products can be expressed as a product of one or more distinct prime numbers. Hence, the count is 6.
Note that [4] or any other subset with 4 are not chosen because prducts having 4 have repeated primes 2.

Input: arr[] = [2, 2, 3]
Output: 5
Explanation: 
Since subsets formed using different indices are considered different, the chosen subsets are:
[2] (using the first 2)
[2] (using the second 2)
[3]
[2, 3] (using the first 2)
[2, 3] (using the second 2)
Each subset has a product that can be expressed as a product of one or more distinct prime numbers. 
Therefore, the answer is 5.
*/

// ============================================================ >> Solution
class Solution
{
    public:
    const int MOD = 1e9 + 7;
    // Fast exponentiation
    long long power(long long a, long long b)
    {
        long long ans = 1;
        while (b)
        {
            if (b & 1)
                ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    
    // Create prime mask for current number
    int getMask(int num)
    {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mask = 0;
        for (int i = 0; i < 10; i++)
        {
            int p = primes[i];
            int cnt = 0;
            while (num % p == 0)
            {
                cnt++;
                num /= p;
            }
            // repeated prime factor
            // invalid number
            if (cnt > 1)
                return -1;
            // store current prime in mask
            if (cnt == 1)
                mask |= (1 << i);
        }
        return mask;
    }
    
    int countSubsets(vector<int> &arr)
    {
        vector<int> freq(31, 0);
        for (int x : arr)
            freq[x]++;
        int ones = freq[1];
        vector<long long> dp(1024, 0);
        dp[0] = 1;
        // process 2 to 30
        for(int num = 2 ; num <= 30 ; num++)
        {
            if(freq[num] == 0)
                continue;
            int currMask = getMask(num);
            if (currMask == -1)
                continue;
            for(int mask = 1023 ; mask >= 0 ; mask--)
            {
                if ((mask & currMask) != 0)
                    continue;
                dp[mask | currMask] = (dp[mask | currMask] + dp[mask] * freq[num]) % MOD;
            }
        }
        long long ans = 0;
        for(int mask = 1 ; mask < 1024 ; mask++)
            ans = (ans + dp[mask]) % MOD;
        ans = (ans * power(2, ones)) % MOD;
        return ans;
    }
};
