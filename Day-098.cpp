/*
Problem name : << Maximum Subset XOR >>

Given an array arr[], choose any subset of elements (possibly all elements) such that the XOR of the chosen elements is maximized.

Examples:
Input : arr[] = [2, 4, 5]
Output: 7
Explanation: The subset {2, 5} has the maximum XOR value.

Input : arr[] = [9, 8, 5]
Output: 13
Explanation: The subset {8, 5} has the maximum XOR value.
*/

// ============================================================== >> Solution
class Solution
{
    public:
    int maxSubsetXOR(vector<int> &arr)
    {
        int n = arr.size();
        int index = 0;
        // Process form MSB to LSB
        for(int bit = 31 ; bit >= 0 && index < n ; bit--)
        {
            int maxInd = index;
            // Find element having the current bit set
            for(int i = index ; i < n ; i++)
                if((arr[i] & (1 << bit)) && arr[i] > arr[maxInd])
                    maxInd = i;
            // CASE : No pivot dound for this bit
            if((arr[maxInd] & (1 << bit)) == 0)
                continue;
            // Place the pivot at the current index
            swap(arr[index], arr[maxInd]);
            // Eliminate the current bit from all other elements
            for(int i = 0 ; i < n ; i++)
                if(i != index && (arr[i] & (1 << bit)))
                    arr[i] = arr[i] ^ arr[index];
            index++;
        }
        int res = 0;
        for(int num : arr)
            res = res ^ num;
        return res;
    }
};
