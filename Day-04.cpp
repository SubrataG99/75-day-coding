/*
Problem name : << Smallest window >>

Given a string s consisting only of the characters '0', '1' and '2', determine the length of the smallest substring that contains all three characters at least once.
If no such substring exists, return -1.

Examples :
Input: s = "10212"
Output: 3
Explanation: The substring "102" is the shortest substring that contains all three characters '0', '1', and '2', so the answer is 3.

Input: s = "12121"
Output: -1
Explanation: The character '0' is not present in the string, so no substring can contain all three characters '0', '1', and '2'. Hence, the answer is -1.
*/

// ==========================================================>> Solution
class Solution {
  public:
    int smallestSubstring(string s)
    {
        int n = s.length();
        // Impossible and useless search
        if(n < 3)
            return -1;
        // Memory for frequency and existence
        int count[3] = {0, 0, 0};
        // Initiating pointers
        int left = 0;
        int minWin = INT_MAX;
        // Traversing through the array
        for(int right = 0; right < n; right++)
        {
            // To get actual value (subtraction of ASCII value)
            int pos = s[right] - '0';
            // count frequency
            count[pos]++;
            // Checking presence
            while(count[0] > 0 && count[1] > 0 && count[2] > 0)
            {
                // Slide the window to minimum
                minWin = min(minWin, (right - left + 1));
                int leftPos = s[left] - '0';
                // Extra characters can be removed
                count[leftPos]--;
                left++;
            }
        }
        // Either not found or the minimum length
        return (minWin == INT_MAX) ? -1 : minWin;
    }
};
