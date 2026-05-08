/*
Problem name : << Remove Invalid Parentheses >>

Given a string s consisting of lowercase letters and parentheses '(' and ')'. A string is considered valid if:
  Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
  Parentheses are properly nested.
Remove the minimum number of invalid parentheses from s so that the resulting string becomes valid.  Return all the possible distinct valid strings in lexicographically sorted order.

Examples :
Input:  = "()())()"
Output: ["(())()", "()()()"]
Explanation: 
The string "()())()" has one extra ')', making it invalid. By removing one ')', we can make it valid in two ways:
Remove the 3rd index ')' -> "(())()"
Remove the 4th index ')' -> "()()()"
Both are valid and require the minimum removals.

Input: s = "(a)())()"
Output: ["(a())()", "(a)()()"]
Explanation: 
We remove one ')' (minimum removals) to make it valid. Possible valid results:
Remove a ')' -> "(a())()"
Remove another ')' -> "(a)()()"

Input: s = ")("
Output: [""]
Explanation: The string ")(" is invalid. Removing both parentheses (minimum removals) gives an empty string "", which is valid.
*/

// ========================================================================= >> Solution
class Solution
{
    public:
    // Function to check if a given string has valid parentheses
    bool isValid(string s)
    {
        int count = 0;
        for (char c : s)
        {
            // Increment for opening bracket
            if (c == '(')
                count++;
            // Decrement for closing bracket
            else if (c == ')')
            {
                count--;
                // If at any point count becomes negative,
                // more ')' than '(' means invalid string
                if (count < 0)
                    return false;
            }
        }
        // Valid only if all '(' are matched
        return count == 0;
    }
    
    vector<string> validParenthesis(string &s)
    {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> result;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            // Check if current string is valid
            if (isValid(curr))
            {
                result.push_back(curr);
                found = true;
            }
            // If valid string found at this level,
            // do not generate next level this ensures minimum removals
            if (found)
                continue;
            // Generate all possible strings by removing one parenthesis
            for (int i = 0; i < curr.length(); i++)
            {
                // Skip non-parenthesis characters
                if (curr[i] != '(' && curr[i] != ')')
                    continue;
                // Remove character at index i
                string next = curr.substr(0, i) + curr.substr(i + 1);
                // Add new string if not already visited
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        // Remove duplicates and sort lexicographically
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
