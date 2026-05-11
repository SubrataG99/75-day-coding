/*
Problem name : << Palindrome Pairs >>

Given an array arr[] consisting of n strings. Determine whether there exists a pair of indices (i, j) such that i ≠ j and the concatenation arr[i] + arr[j] forms a palindrome. Return true if such a pair exists; otherwise, return false.
Note: A string is considered a palindrome if it reads the same forward and backward.

Examples:

Input: arr[] = ["geekf", "geeks", "or", "keeg", "abc", "bc"]
Output: true
Explanation: There is a pair "geekf" and "keeg". Their concatenation "geekfkeeg" is a palindrome.

Input: arr[] = ["abc", "xyxcba", "geekst", "or", "bc"]
Output: true
Explanation: There is a pair "abc" and "xyxcba". Their concatenation "abcxyxcba" is a palindrome.

Input: arr[] = ["aa"]
Output: false
Explanation: There is only one string present, so the output is false.
*/

// ===============================================>> Solution
class Solution
{
    public:
    bool isP(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    bool palindromePair(vector<string>& arr)
    {
        int n = arr.size();
        // Map: reversed string -> index (or simply mark that this string exists)
        unordered_map<string, int> revMap;
        for (int i = 0; i < n; i++)
        {
            string r = arr[i];
            reverse(r.begin(), r.end());
            revMap[r] = i;
        }
        // Check each word: split into left and right parts
        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            int L = s.size();
            // Try all splits: s = left + right
            for (int j = 0; j <= L; j++)
            {
                string left  = s.substr(0, j);  // length = j
                string right = s.substr(j);     // length = L - j
                // Check if left + right + (some other word) forms a palindrome
                // Case 1: left + w + right = palindrome, if w = reverse(left) AND right is palindrome
                if (isP(right))
                    if (revMap.count(left) && revMap[left] != i)
                        return true;
                // Case 2: left + w + right = palindrome, if w = reverse(right) AND left is palindrome
                if (j > 0 && isP(left))
                    if (revMap.count(right) && revMap[right] != i)
                        return true;
            }
        }
        return false;
    }
};
