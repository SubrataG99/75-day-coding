/*
Problem name : << Check Preorder of BST >>

Given an array arr[ ] consisting of distinct integers, check if the given array can represent preorder traversal of a BST.

Examples :
Input: arr[] = [2, 4, 3]
Output: true
Explaination: Given arr[] can represent preorder traversal of following BST:
 
Input: arr[] = [2, 4, 1]
Output: false
Explaination: Given arr[] cannot represent preorder traversal of a BST.
*/

// ============================================= >> Solution
class Solution
{
    public:
    bool canRepresentBST(vector<int> &arr)
    {
        stack<int> s;
        // Initialize current root as minimum possible value
        int root = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            // If we find a node who is on right side and smaller than root, return false
            if(arr[i] < root)
                return false;
            // If pre[i] is in right subtree of stack top,Keep removing items smaller than pre[i] and make the last removed item as new root.
            while(!s.empty() && (s.top() < arr[i]))
            {
                root = s.top();
                s.pop();
            }
            // At this point either stack is empty or pre[i] is smaller than root, push pre[i]
            s.push(arr[i]);
        }
        return true;
    }
};
