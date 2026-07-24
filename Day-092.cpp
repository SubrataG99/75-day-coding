/*
Problem name : << Longest Consecutive Path in Binary tree >>

Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.
The path must move from parent to child only and follow increasing consecutive values.
If no such path exists, return -1.

Examples:
Input: root[] = [1, 2, 3]
Output: 2
Explanation : Longest sequence is 1, 2. So answer for this test case is 2.

Input : root[] = [10, 20, 30, 40, N, 60, 90]
Output : -1
Explanation: For the above test case no sequence is possible. So output is -1.
*/

// =================================================== >> Solution
/* Structure of Binary Tree Node
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution
{
    public:
    void dfs(Node *curr, Node *parent, int currL, int &longPath)
    {
        if(curr == nullptr)
            return;
        // Check whether consecutive sequence continues
        if(parent && curr->data == parent->data + 1)
            currL++;
        else
            currL = 1;
        // Update the best answer found so far
        longPath = max(longPath, currL);
        dfs(curr->left, curr, currL, longPath);
        dfs(curr->right, curr, currL, longPath);
    }
    
    int longestConsecutive(Node* root)
    {
        if(root == nullptr)
            return -1;
        int longpath = 0;
        dfs(root, nullptr, 0, longpath);
        return(longpath == 1 ? -1 : longpath);
    }
};
