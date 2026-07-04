/*
Problem name : << Max Gap Between Two Same >>

Given a string s consisting of lowercase English letters, find the maximum number of characters between any two identical characters. If no character repeats, return -1.

Examples :
Input: s = "socks"
Output: 3
Explanation: There are 3 characters between the two occurrences of 's'.

Input: s = "for"
Output: -1
Explanation: No repeating character present.
*/

// =============================================== >> Solution
class Solution
{
    public:
    int maxCharGap(string &s)
    {
        vector<int> alpha(26, -1);
        int res = -1;
        for(int i = 0 ; i < (int)s.size(); i++)
        {
            int ch = s[i] - 'a';
            // First occurence
            if(alpha[ch] == -1)
                alpha[ch] = i;
            // chars between first and current occurence
            else
                res = max(res, i - alpha[ch] - 1);
        }
        return res;
    }
};
