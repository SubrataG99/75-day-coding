/*
Problem name : << Vertical Sum >>
Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.
*/

// ==========================================>> Solution

/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution
{
    public:
    struct dll
    {
        int data;
        dll *prev, *next;
        dll(int val)
        {
            data = val;
            prev = next = NULL;
        }
    };
    
    void vSum(Node *root, dll*curr)
    {
        if(root == NULL)
            return;
        curr->data += root->data;
        // For left subtree
        if(root->left)
        {
            if(curr->prev == NULL)
            {
                curr->prev = new dll(0);
                curr->prev->next = curr;
            }
            vSum(root->left, curr->prev);
        }
        // Right subtree
        if(root->right)
        {
            if(curr->next == NULL)
            {
                curr->next = new dll(0);
                curr->next->prev = curr;
            }
            vSum(root->right, curr->next);
        }
    }
    
    vector<int> verticalSum(Node* root)
    {
        if(root == NULL)
            return {};
        dll *head = new dll(0);
        vSum(root, head);
        // backtrack to the left most part
        while(head->prev)
            head = head->prev;
        vector<int> res;
        // Traverse through all columns
        while(head)
        {
            res.push_back(head->data);
            head = head->next;
        }
        return res;
    }
};
