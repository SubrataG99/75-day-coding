/*
Problem name : << Max Dot Product with 0 Insertions >>

Given two arrays a[] and b[] of positive integers of size n and m respectively, where m ≤ n.  You are allowed to insert zeros anywhere into the second array b so that its length becomes equal to n.
The dot product of two arrays of equal length n is defined as: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].
Return the maximum possible dot product of the two arrays.

Examples :
Input: a[] = [2, 3, 1, 7, 8], b[] = [3, 6, 7]
Output: 107
Explanation: Maximum dot product is obtained after inserting 0 at the first and third positions in array b.
Therefore b becomes [0, 3, 0, 6, 7]. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107. Therefore answer for this test case is 107.

Input: a[] = [1, 2, 3], b[] = [4] 
Output: 12 
Explanation: Maximum dot product is obtained after inserting 0 at the first and second positions in array b.
Therefore b becomes [0, 0, 4]. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12. Therefore answer for this test case is 12.
*/

// =========================================================== >> Solution
class Solution
{
    public:
    int maxDotProduct(vector<int>& a, vector<int>& b)
    {
        int na = a.size();
        int nb = b.size();
        vector<int> dp(nb + 1, -1e9);
        dp[0] = 0;
        for(int i = 1 ; i <= na ; i++)
            for(int j = nb ; j >= 1 ; j--)
                // Calculate the maximum dot product at position j by choosing between not including b[j-1] and including b[j-1] update dp[j] with the maximum value
                dp[j] = max(dp[j], dp[j - 1] + (a[i - 1] * b[j - 1]));
        return dp[nb];
    }
};
