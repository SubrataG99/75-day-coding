/*
Problem name : << Search for Subarray >>

You are given two integer arrays a[] and b[]. Return all the starting indexes of all the occurences of b[] as a subarray in a[].

Examples:

Input: a[] = [2, 4, 1, 0, 4, 1, 1], b[] = [4, 1]
Output: [1, 4]
Explanation: b[] occurs as a subarray in a[] from index 1 to 2 and from index 4 to 5.

Input: a[] = [2, 4, 1, 0, 0, 3], b[] = [0]
Output: [3, 4]
Explanation: b[] occurs as a subarray in a[] from index 3 to 3 and from index 4 to 4.

Input: a[] = [1, 3, 5, 3, 0], b[] = [1, 3, 0]
Output: []
Explanation: There is no subarray occurs as b[] in a[]
*/

// =========================================================== >> Solution
class Solution
{
    public:
    void getLPS(vector<int> &patt, vector<int> &lps)
    {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < patt.size())
        {
            if(patt[i] == patt[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    vector<int> search(vector<int> &a, vector<int> &b)
    {
        vector<int> sa;
        int lena = a.size();
        int lenb = b.size();
        // If no pattern then return empty
        if(lenb == 0)
            return sa;
        vector<int> lps(lenb);
        getLPS(b, lps);
        int i = 0;
        int j = 0;
        while(i < lena)
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
                if(j == lenb)
                {
                    sa.push_back(i - j);
                    j = lps[j - 1];
                }
            }
            else
            {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return sa;
    }
};
