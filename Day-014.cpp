/*
Problem name : << Check if subtree >>

Given two binary trees with roots root1 (for tree T) and root2 (for tree S), each containing at most N nodes. Determine whether tree S is a subtree of tree T. Return true if S is a subtree of T, otherwise return false.

Note: A tree S is considered a subtree of T if there exists a node in T such that the subtree rooted at that node is identical to S. Two trees are identical if they have the same structure and the same node values.

Examples:
Input: root1 = [1, 2, 3, N, N, 4], root2 = [3, 4]             
Output: true 
Explanation: In the tree rooted at root1, the subtree starting at node 3 is identical to the tree rooted at root2 (same structure and node values). Hence, root2 is a subtree of root1, so the output is true.

Input: root1 = [26, 10, N, 20, 30, 40, 60], root2 = [26, 10, N, 20, 30, 40, 60]
Output: true 
Explanation: Both root1 and root2 represent identical trees. So, root2 is a subtree of root1, and the output is true.
*/

// ================================================= >> Solution
/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/


// Serialize tree using preorder with null markers
void serialize(Node *root, string &s)
{
    // Null node => add marker
    if (root == nullptr)
    {
        s += "# ";
        return;
    }
    // Add current node
    s += to_string(root->data) + " ";
    // Recurse on left and right
    serialize(root->left, s);
    serialize(root->right, s);
}

// Build LPS array for KMP
vector<int> buildLPS(string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
            lps[i++] = ++len;
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                i++;
        }
    }
    return lps;
}

// KMP search: check if pattern exists in text
bool kmpSearch(string &text, string &pattern)
{
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;
    while (i < text.length())
    {
        // Characters match => move both
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        // Full pattern matched
        if (j == pattern.length())
            return true;
        // Mismatch after some matches
        else if (i < text.length() && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

class Solution
{
    public:
    bool isSubTree(Node *root1, Node *root2)
    {
        // Serialize both trees
        string s1 = "", s2 = "";
        serialize(root1, s1);
        serialize(root2, s2);
        // Apply KMP to check substring
        return kmpSearch(s1, s2);
    }
};
