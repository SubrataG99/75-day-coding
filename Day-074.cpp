/*
Problem name : << Max Sum Path in Two Arrays >>

Given two sorted arrays of distinct integers in increasing order a[] and b[], which may have some common elements, find the maximum sum of a path from the beginning of any array to the end of any array. You may switch from one array to the other only at common elements.
Note:  When switching, count the common element only once.

Examples : 
Input: a[] = [2, 3, 7, 10, 12], b[] = [1, 5, 7, 8]
Output: 35
Explanation: The path will be (1 + 5 + 7 + 10 + 12) = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.

Input: a[] = [1, 2, 3], b[] = [3, 4, 5]
Output: 15
Explanation: The path will be (1 + 2 + 3 + 4 + 5) = 15.
*/

// ================================================= >> Solution
class Solution
{
    public:
    int maxPathSum(vector<int> &a, vector<int> &b)
    {
        int i = 0, j = 0;
        int n1 = a.size();
        int n2 = b.size();
        long long res = 0, s1 = 0, s2 = 0;
        // Traverse to find the sum in each path
        while(i < n1 && j < n2)
        {
            // Add up if the array element is not common
            if(a[i] < b[j])
                s1 = s1 + a[i++];
            else if(a[i] > b[j])
                s2 = s2 + b[j++];
            // If common switch which has the max value counting the common only once.
            else
            {
                res = res + max(s1, s2) + a[i];
                s1 = 0;
                s2 = 0;
                i++;
                j++;
            }
        }
        // Keep summing up until the end of the array (if n1 != n2)
        while(i < n1)
            s1 = s1 + a[i++];
        while(j < n2)
            s2 = s2 + b[j++];
        // Get the max of the rest of the array element
        res = res + max(s1, s2);
        return (int)res;
    }
};
