/*
Problem name : << Check if an Array is Max Heap >>

Given an array arr[], determine whether it represents the level-order traversal of a valid max heap. Return true if it does; otherwise, return false.

Examples :

Input: arr[] = [90, 15, 10, 7, 12, 2]
Output: true
Explanation: The given array represents the following tree. Each parent node is greater than or equal to its children, so the max-heap property holds.
 
Input: arr[] = [9, 15, 10, 7, 12, 11]
Output: false
Explanation: The given array represents the following tree. It does not satisfy the max-heap property, as 9 is smaller than 15 and 10, and 10 is smaller than 11.
*/

// ==================================================================>> Solution
class Solution
{
    public:
    bool isMaxHeap(vector<int> &arr)
    {
        int n = arr.size();
        // Traverse internal nodes
        for(int i = 0; i <= (n - 2)/2; i++)
        {
            // Check left child
            if(arr[2*i+1] > arr[i])
                return false;
            // Check right child and also if index exists
            if((2*i+2 < n) && (arr[2*i+2] > arr[i]))
                return false;
        }
        // default value
        return true;
    }
};
