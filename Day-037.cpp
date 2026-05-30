/*
Problem name : << Replace with XOR of Adjacent >>

Given an array arr[] of n integers, modify the array in-place such that each element is replaced with the XOR of its adjacent elements.
For the first element, update arr[0] = arr[0] ^ arr[1].
For the last element, update arr[n-1] = arr[n-2] ^ arr[n-1].
For all other elements, update arr[i] = arr[i-1] ^ arr[i+1].
Note: Here, a ^ b represents the XOR operation between a and b. 

Examples :
Input : arr[] = [2, 1, 4, 7]
Output : [3, 6, 6, 3]
Explanation:
At index 0, arr[0] ^ arr[1] = 2 ^ 1 = 3
At index 1, arr[0] ^ arr[2] = 2 ^ 4 = 6
At index 2, arr[1] ^ arr[3] = 1 ^ 7 = 6
At index 3, arr[2] ^ arr[3] = 4 ^ 7 = 3
Thus, the updated array becomes [3, 6, 6, 3].

Input : arr[] = [5, 9, 2, 6, 7]
Output: [12, 7, 15, 5, 1]
Explanation:
At index 0, arr[0] ^ arr[1] = 5 ^ 9 = 12
At index 1, arr[0] ^ arr[2] = 5 ^ 2 = 7
At index 2, arr[1] ^ arr[3] = 9 ^ 6 = 15
At index 3, arr[2] ^ arr[4] = 2 ^ 7 = 5
At index 4, arr[3] ^ arr[4] = 6 ^ 7 = 1
Thus, the updated array becomes [12, 7, 15, 5, 1].
*/

// ===========================================================>> Solution
class Solution
{
    public:
    void replaceElements(vector<int>& arr)
    {
        int n = arr.size();
        // For XOR at least 2 elements are needed
        if(n < 2)
            return;
        // Take a backup to start calculating
        int prev = arr[0];
        // Update element zero
        arr[0] = arr[0] ^ arr[1];
        // Traverse to update
        for(int i = 1 ; i < arr.size() - 1 ; i++)
        {
            // Store new XOR value
            int val = prev ^ arr[i + 1];
            // change the prev value to current array element
            prev = arr[i];
            // Update the array value with the XOR result
            arr[i] = val;
        }
        // Update the last element with 2nd element xor
        arr[n - 1] = arr[n - 1] ^ prev;
    }
};
