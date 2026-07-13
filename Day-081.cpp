/*
Problem name : << Rearrange the Array >>

Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing all integers from 1 to n exactly once.
The array b[] defines a rearrangement operation.
During a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).
We must do at least one operation on a[].
Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: [1, 2, 3, ..., n] again.
Note:  The answer can be large, so return the answer modulo 10^9+7.

Examples:
Input: b[] = [1, 2, 3]
Output: 1
Explanation: Initially, a[] = [1, 2, 3] and b[] = [1, 2, 3]
After one operation:
a[1] = 1 goes to position 1 as b[1] = 1.
a[2] = 2 goes to position 2.
a[3] = 3 goes to position 3.
so, now a[] becomes [1, 2, 3].
All elements remain at their original positions. Hence, the answer is 1.

Input: b[] = [2, 3, 1, 5, 4]
Output: 6
Explanation: The sequence of arrays obtained after each operation is:
Initially : [1, 2, 3, 4, 5]
1 : [3, 1, 2, 5, 4]
2 : [2, 3, 1, 4, 5]
3 : [1, 2, 3, 5, 4]
4 : [3, 1, 2, 4, 5]
5 : [2, 3, 1, 5, 4]
6 : [1, 2, 3, 4, 5]
After 6 operations, all elements return to their original positions simultaneously. Therefore, the answer is 6.
*/

// =============================================== >> Solution
class Solution
{
    public:
    // Computes (x^y) % MOD using binary exponentiation.
    static const int mod = 1e9 + 7;
    long long modPow(int x, int y)
    {
        long long res = 1;
        while(y)
        {
            if(y & 1)
                res = (res * x) % mod;
            x = (1LL * x * x) % mod;
            y = y >> 1;
        }
        return res;
    }
    // Returns the minimum operations required to restore the array to its original state.
    int minOperations(vector<int> &b)
    {
        int n = b.size();
        vector<bool> vis(n, false);
        vector<int> cycles;
        // Find lengths of all disjoint cycles.
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                int len = 0;
                int cur = i;
                while(!vis[cur])
                {
                    vis[cur] = true;
                    // Convert to 0-based indexing.
                    cur = b[cur] - 1;
                    len++;
                }
                cycles.push_back(len);
            }
        }
        // Build SPF (Smallest Prime Factor) array
        vector<int> spf(n + 1);
        for(int i = 0 ; i <= n; i++)
            spf[i] = i;
        for(int i = 2 ; i * i <= n; i++)
            if(spf[i] == i)
                for(int j = i * i ; j <= n ; j = j + i)
                    if(spf[j] == j)
                        spf[j] = i;
        unordered_map<int, int> mpow;
        // Store maximum exponent of every prime appearing in any cycle length.
        for(int len : cycles)
        {
            unordered_map<int, int> freq;
            while(len > 1)
            {
                int p = spf[len];
                int cnt = 0;
                while(len % p == 0)
                {
                    len = len / p;
                    cnt++;
                }
                freq[p] = cnt;
            }
            for(auto &it :freq)
                mpow[it.first] = max(mpow[it.first], it.second);
        }
        // Reconstruct LCM modulo MOD
        long long res = 1;
        for(auto &it : mpow)
            res = (res * modPow(it.first, it.second)) % mod;
        return (int)res;
    }
};
