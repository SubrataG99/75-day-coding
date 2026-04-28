/*
Problem name : << Longest Repeating Character Replacement >>

Given a string s of length n consisting of uppercase English letters and an integer k, you are allowed to perform at most k operations.  In each operation, you can change any character of the string to any other uppercase English letter. Determine the length of the longest substring that can be transformed into a string with all identical characters after performing at most k such operations.

Examples:

Input: s = "ABBA", k = 2 
Output: 4 
Explanation: The string "ABBA" can be fully converted into the same character using at most 2 changes. By replacing both 'A' with 'B', it becomes "BBBB". Hence, the maximum length is 4.

Input: s = "ADBD", k = 1
Output: 3
Explanation: In the string "ADBD", we can make at most 1 change. By changing 'B' to 'D', the string becomes "ADDD", which contains a substring "DDD" of length 3.
*/

// ====================================================================>> Solution
class Solution
{
  public:
    int longestSubstr(string& s, int k)
    {
        int n = s.length();
        // For longest repeating character count
        int lrc = 0;
        int maxF = 0;
        // To count frequency
        int a[26]{};
        // To check the window
        int left = 0;
        for(int i = 0; i < n; i++)
        {
            a[int(s[i]) - 'A']++;
            maxF = max(maxF, a[int(s[i]) - 'A']);
            // Check the window
            while((i - left + 1 - maxF) > k)
            {
                a[int(s[left]) - 'A']--;
                left++;
                for(int j = 0; j < 26 ; j++)
                {
                    maxF = max(maxF, a[j]);
                }
            }
            lrc = max(lrc, (i - left + 1));
        }
        return lrc;
    }
};
