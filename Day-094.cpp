/*
Problem name : << Complete Binary Tree Traversal with Array Input >>

Given an integer array arr[] representing the nodes of a Complete Binary Tree in level order traversal, return the nodes at each level in sorted ascending order.
For every level of the binary tree, sort the values present at that level independently and return the resulting levels as a 2D array, where the i-th row contains the sorted values of the i-th level.

Examples:
Input: arr[] = [7, 6, 5, 4, 3, 2, 1]
Output: [[7], [5, 6], [1, 2, 3, 4]]
Explanation: The complete binary tree formed from the given level order traversal is:
The nodes at each level after sorting are:
Level 0: [7]
Level 1: [5, 6]
Level 2: [1, 2, 3, 4]

Input: arr[] = [7, 16, 1, 4, 13]
Output: [[7], [1, 16], [4, 13]]
Explanation: The complete binary tree formed from the given level order traversal is:
The nodes at each level after sorting are:
Level 0: [7]
Level 1: [1, 16]
Level 2: [4, 13]
*/

// ====================================================== >> Solution
class Solution
{
    public:
    vector<vector<int>> levelSort(vector<int>& arr)
    {
        vector<vector<int>> res;
        // Points to first element of current level
        int curr = 0;
        // Level starts fom 1
        int level = 1;
        // Process levels until all elements are covered
        while(curr < arr.size())
        {
            // Calculate the ending position of the current level
            int levEnd = (1 << level) - 1;
            // Make sure we do not go outside the array
            levEnd = min(levEnd, (int)arr.size());
            // Sort only the elements of the current level
            sort(arr.begin() + curr, arr.begin() + levEnd);
            // Initialise every time to get an empty list/vector for every level
            vector<int> levels;
            for(int i = curr ; i < levEnd; i++)
                levels.push_back(arr[i]);
            // Add the vector to final result
            res.push_back(levels);
            // Move to next level
            curr = levEnd;
            level++;
        }
        return res;
    }
};
