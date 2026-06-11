/*
Problem name : << Equal Point in Brackets >>

Given a string s of opening and closing brackets '(' and ')' only, find an equal point in the string. An equal point is a position k (0-based) such that the number of opening brackets before position k is equal to the number of closing brackets from position k to the end of the string. If multiple such points exist, return the first valid position.
The string can be split at any position from 0 to n, where n is the length of the string.
If we split at 0, it means there is an empty string on left.
If we split at n, it means there is an empty string on right.

Examples:
Input: s = "(())))("
Output: 4
Explanation:
 
Input : s = "))"
Output: 2
Explanation: After index 2, the string splits into "))" and an empty string. The number of opening brackets in the first part is 0 and the number of closing brackets in the second part is also 0.
*/

// =========================================================> Solution
class Solution
{
    public:
    int findIndex(string &s)
    {
        int n = s.size();
        int open = 0;
        int close = 0;
        // Collecting all closing bracket
        for(int i = 0 ; i < n ; i++)
            if(s[i] == ')')
                close++;
        // Traverse to count the balancing position
        for(int i = 0 ; i <= n ; i++)
        {
            if(open == close)
                return i;
            if(i < n)
            {
                if(s[i] == '(')
                    open++;
                if(s[i] == ')')
                    close--;
            }
        }
    }
};
