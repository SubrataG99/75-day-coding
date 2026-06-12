/*
Problem name : << Check Repeated Substring with K Replacements >>

Given a string s and an integer k, check if it is possible to convert s to a string that is repetition of a substring with k characters else returns false. In order to convert we can replace one substring of length k with any k characters.

Examples:
Input: s = "abcbedabcabc",  k = 3
Output: true
Explanation: Replace "bed" with "abc" so that the whole string becomes repetition of "abc".

Input: s = "bdac", k = 2
Output: true
Explanation: The string can be divided into substrings of length k: ["bd", "ac"]. 
Since there are exactly two substrings and both are different, we can make them identical by replacing one substring with the other. Hence, the result is true.

Input: s = "abcdabcd", k = 2
Output: false
Explanation: Since we are allowed to change only one instance, we cannot covert.
*/

// ==========================================> Solution
class Solution
{
    public:
    bool kSubstr(string &s, int k)
    {
        int n = s.size();
        // Needs to broken down to exact pieces
        if(n % k)
            return false;
        unordered_map<string, int> m;
        // Checking patterns
        for(int i = 0; i < n ; i+=k)
            m[s.substr(i, k)]++;
        // If only single pattern
        if(m.size() == 1)
            return true;
        // If more than 2 patterns
        if(m.size() != 2)
            return false;
        // Check if the different pattern can be replaced or not
        if((m.begin()->second == ((n/k) - 1)) || (m.begin()->second == 1))
            return true;
        return false;
    }
};
