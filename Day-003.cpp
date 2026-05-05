/* 
Problem name : << Common in 3 sorted arrays >>

Given three sorted arrays in non-decreasing order, return all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array.

Examples :

Input: a[] = [1, 5, 10, 20, 40, 80], b[] = [6, 7, 20, 80, 100], c[] = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: The elements 20 and 80 appear in all three arrays a, b, and c, making them the only common elements, so the output is [20, 80].

Input: a[] = [1, 2, 3, 4, 5], b[] = [6, 7], c[] = [8, 9, 10]
Output: []
Explanation: Since none of the elements in arrays a, b, and c appear in all three arrays, there are no common elements, so the output is [].

Input:  a[] = [1, 1, 1, 2, 2, 2], b[] = [1, 1, 2, 2, 2], c[] = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Ignoring duplicates, 1 and 2 are present in all three arrays, so the output is [1, 2].
*/

// =========================================================================>> Solution
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        // Stack to put the common elements
        vector<int> f;
        // Pointer to traverse in the array
        int i = 0 ;
        int j = 0;
        int k = 0 ;
        // Traversing the arrays
        while(i < a.size() && j < b.size() && k < c.size()) {
            // Check if common element
            if(a[i] == b[j] && b[j] == c[k])
            {
                f.push_back(a[i]);
                i++;
                j++;
                k++;
                // Check if there are duplicates on the array which looks common
                while(i < a.size() && a[i] == a[i - 1])
                {
                    i++;
                }
                while(j < b.size() && b[j] == b[j - 1])
                {
                    j++;
                }
                while(k < c.size() && c[k] == c[k - 1])
                {
                    k++;
                }
            }
            // If element is less, the pointer needs to be increased
            else if(a[i] < b[j])
                i++;
            // else if(a[i] > b[j])
            //     j++;
            else if(b[j] < c[k])
                j++;
            // else if(b[j] > c[k])
            else
                k++;
        }
        return f;
    }
};
