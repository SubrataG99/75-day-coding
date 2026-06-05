/*
Problem name : << Lexicographically smallest after removing 'k' >>

Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after removing exactly k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. You can remove any k characters.
Note: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.

Examples:
Input: s = "fooland", k = 2
Output: "and" 
Explanation: As the size of the string = 7 which is not a power of 2, hence k = 4. After removing 4 characters from the given string, the lexicographically smallest string is "and".

Input: s = "code", k = 4
Output: "cd"
Explanation: As the length of the string = 4, which is 2 to the power 2, hence k = 2. Hence, lexicographically smallest string after removal of 2 characters is "cd".
*/

// ========================================================>> Solution
class Solution
{
    public:
    string lexicographicallySmallest(string &s, int k)
    {
        int n = s.size();
        // Check if string size is power of 2
        if((n & (n - 1)) == 0)
            k = k / 2;
        else
            k = k * 2;
        // In case the modified k is more than the strings to remove
        if(k >= n)
            return "-1";
        
        stack<char> st;
        string out = "";
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            // Remove the letters in stack if in lexical way
            while(!st.empty() && (s[i] < st.top()) && (k > 0))
            {
                st.pop();
                k--;
            }
            // push into stack if non-lexical way
            st.push(s[i]);
        }
        // If lop ends and all are done in lexical way but k is left
        while(!st.empty() && (k > 0))
        {
            st.pop();
            k--;
        }
        // Take the stack and form the output word
        while(!st.empty())
        {
            out = out + st.top();
            st.pop();
        }
        // reverse the string as it will be in reverse order
        reverse(out.begin(), out.end());
        return out;
    }
};
