/*
Problem name : << Construct a Full Binary Tree >>

Given two arrays pre[] and preMirror[] of size n containing unique elements, where pre[] represents the preorder traversal of a full binary tree and preMirror[] represents the preorder traversal of its mirror tree, construct the original full binary tree using these traversals.
Note: A general binary tree cannot be uniquely constructed using these two traversals. However, a full binary tree can be constructed uniquely from the given traversals without any ambiguity.

Examples:
Input: pre[] = [0,1,2], preMirror[] = [0,2,1] 
Output: [0, 1, 2]

Input: pre[] = [1, 2, 4, 5, 3, 6, 7], preMirror[] = [1, 3, 7, 6, 2, 5, 4]
Output: [1, 2, 4, 5, 3, 6, 7]
*/

// ================================================================ >> Solution

/* Structure of Binary Tree Node
class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution
{
    public:
    
    Node *buildTree(vector<int> &pre, vector<int> &preMirror, int &preIndex, int left, int right, unordered_map<int, int> &mp, int n)
    {
        // Base case
        if(preIndex >= n || left > right)
            return NULL;
        // Create current node
        Node *root = new Node(pre[preIndex++]);
        // Leaf node
        if(left == right)
            return root;
        // Find next preorder element index in preMirror
        int mirrorIndex = mp[pre[preIndex]];
        if((mirrorIndex >= left) && (mirrorIndex <= right))
        {
            // Construct left subtree
            root->left = buildTree(pre, preMirror, preIndex, mirrorIndex, right, mp, n);
            // Construct right subtree
            root->right = buildTree(pre, preMirror, preIndex, left + 1, mirrorIndex - 1, mp, n);
        }
        return root;
    }
    
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror)
    {
        int n = pre.size();
        // store indices of mirroe preorder traversal
        unordered_map<int, int> mp;
        for(int i = 0; i < n ; i++)
            mp[preMirror[i]] = i;
        int preIndex = 0;
        return buildTree(pre, preMirror, preIndex, 0, n - 1, mp, n);
    }
};
