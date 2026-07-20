/*
Problem name : << Shortest Unique Prefix for Every Word >>

Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the array. A prefix is unique if it is not a prefix of any other string in the array.
Note: No string in the given array is a prefix of another string.

Examples :
Input: arr[] = ["zebra", "dog", "duck", "dove"]
Output: ["z", "dog", "du", "dov"]
Explanation: z => zebra, dog => dog, duck => du, dove => dov 

Input: arr[] = ["geeksgeeks", "geeksquiz", "geeksforgeeks"]
Output: ["geeksg", "geeksq", "geeksf"]
Explanation: geeksgeeks => geeksg, geeksquiz => geeksq, geeksforgeeks => geeksf
*/

// ================================================== >> Solution
class Solution
{
    class Node
    {
        private :
            vector<Node*> children;
            int freq;
            char ch;
        public :
        Node(char x)
        {
            freq = 0;
            ch = x;
            children = vector<Node*>(26, nullptr);
        }
        
        void insert(string& word)
        {
            Node* curr = this;
            for(char c : word)
            {
                if(curr -> children[c - 'a'] == nullptr)
                    curr -> children[c - 'a'] = new Node(c);
                curr = curr -> children[c - 'a'];
                curr -> freq++;
            }
        }
        
        int findPrefix(string& word)
        {
            Node* curr = this;
            for(int i = 0 ; i < word.length() ; i++)
            {
                curr = curr -> children[word[i] - 'a'];
                if(curr -> freq == 1)
                    return i;
            }
            return word.length() - 1;
        }
        
        void delTrial(Node* root)
        {
            if(root == nullptr)
                return;
            for(int i = 0 ; i < 26 ; i++)
            {
                delTrial(root -> children[i]);
                delete root -> children[i];
            }
        }
    };
    
    public:
    vector<string> findPrefixes(vector<string>& arr)
    {
        int n = arr.size();
        Node* root = new Node('*');
        for(int i = 0 ; i < n ; i++)
            root -> insert(arr[i]);
        vector<string> res;
        for(int i = 0 ; i < n ; i++)
        {
            string word = arr[i];
            int endIndex = root -> findPrefix(word);
            res.push_back(word.substr(0, endIndex + 1));
        }
        root -> delTrial(root);
        return res;
    }
};
