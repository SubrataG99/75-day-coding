/*
Problem name : << Minimum Insert and Delete to Convert >>

Given two arrays a[] and b[] of size n and m respectively, find the minimum number of insertions and deletions on the array a[], required to make both the arrays identical.
Note: Array b[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at the end.

Examples :
Input: a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
Output: 4
Explanation:
Delete 2 from a: a[] = [1, 5, 3, 1]
Insert 3 after 1: a[] = [1, 3, 5, 3, 1]
Delete the last two elements: a[] = [1, 3, 5]
Total operations = 1 + 1 + 2 = 4.

Input: a[] = [1, 4], b[] = [1, 4]
Output : 0
Explanation: Both the Arrays are already identical.
*/

// ===================================================== >> Solution
class Solution
{
    public:
    int minInsAndDel(vector<int> &a, vector<int> &b)
    {
        int na = a.size();
        int nb = b.size();
        // Store elements of b
        unordered_map<int, int> m;
        for(int i = 0 ; i < nb ; i++)
            m[b[i]] = i;
        // Store mapped indices
        vector<int> v;
        for(int x : a)
            // If element is in b
            if(m.count(x))
                v.push_back(m[x]);
        vector<int> lis;
        for(int x : v)
        {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            // Insert element
            if(it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        int len = lis.size();
        // Store final answer
        int res = (na - len) + (nb - len);
        return res;
    }
};
