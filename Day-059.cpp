/*
Problem name : << Choose and Swap >>

Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.

Examples:
Input: s = "ccad"
Output: "aacd"
Explanation: In ccad, we choose a and c and after doing the replacement operation once, we get aacd and this is the lexicographically smallest string possible. 

Input: s = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for a and b but that is not lexicographically smaller than abba. So, the answer is abba.
*/

// =================================================================================== >> Solution

class Solution
{
    public:
    string chooseSwap(string &s)
    {
        int n = s.size();
        vector<int> first(26, -1);
        for(int i = 0 ; i < n ; i++)
        {
            int ch = s[i] - 'a';
            if(first[ch] == -1)
                first[ch] = i;
        }
        char x = 0;
        char y = 0;
        int pos = -1;
        for(int i = 0; i < n ; i++)
        {
            int cur = s[i] - 'a';
            for(int c = 0 ; c < cur ; c++)
            {
                if(first[c] > i)
                {
                    pos = i;
                    x = s[i];
                    y = char('a' + c);
                    break;
                }
            }
            if(pos != -1)
                break;
        }
        if(pos == -1)
            return s;
        string res = s;
        // Swap all x and y
        for(char &ch : res)
        {
            if(ch == x)
                ch = y;
            else if(ch == y)
                ch = x;
        }
        return res;
    }
};
