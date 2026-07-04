/*
Problem name : << Substrings with more 1's than 0's >>

Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.

Examples:
Input: s = "011"
Output: 4
Explanation: There are 4 substring which has more 1s than 0s. i.e "011","1","11" and "1"

Input: s = "0000"
Output: 0
Explanation: There is no substring with more 1s than 0s
*/

// ======================================== >> Solution
class Solution
{
    public:
    int countSubstring(string& s)
    {
        int n = s.size();
        int ans = 0;
        // "zero" acts as the base index in frequency array, we shift indices by n to avoid negative indexing
        int zero = n;
        // Stores count of invalid prefix states (where number of 0's >= number of 1's)
        int minus = 0;
        // Frequency array to store occurrences of prefix balances
        vector<int> mp(2 * n + 1, 0);
        int curr = zero;
        // Step 1: Build prefix balance frequencies
        for(auto i : s)
        {
            // Treat: '1' as +1 ; '0' as -1
            if(i == '0')
                curr--;
            else
                curr++;
            // If current balance <= base balance, then substring is invalid
            if(curr <= zero)
                minus++;
            // Store frequency of current balance
            mp[curr]++;
        }
        // Step 2: Count valid substrings
        for(int i = 0 ; i < n ; i++)
        {
            ans = ans + (n - i - minus);
            // Update values while moving start index
            // Case 1: Current character is '1'
            if(s[i] == '1')
            {
                // Remove old prefix balance frequency
                mp[zero + 1]--;
                // Shift base balance
                zero++;
                // Update invalid count
                minus = minus + mp[zero];
            }
            // Case 2: Current character is '0'
            else
            {
                // Remove old prefix balance frequency
                mp[zero - 1]--;
                // Shift base balance
                zero--;
                // Current invalid state removed
                minus--;
                // Remove additional invalid balances
                minus = minus - mp[zero + 1];
            }
        }
        return ans;
    }
};
