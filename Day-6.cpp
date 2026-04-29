/*
Problem name : << Min Swaps to Group 1s >>

You are given a binary array arr[] consisting only of 0s and 1s. Determine the minimum number of swaps required to group all the 1s together in a contiguous subarray. A swap operation allows you to choose any two indices i and j and exchange their values (i.e., swap(arr[i], arr[j])). If the array contains no 1s, return -1.

Examples:

Input: arr[] = [1, 0, 1, 0, 1]
Output: 1
Explanation: Only 1 swap is required to group all 1's together. Swapping index 1 and 4 will give arr[] = [1, 1, 1, 0, 0].

Input: arr[] = [1, 0, 1, 0, 1, 1] 
Output: 1
Explanation: Only 1 swap is required to group all 1's together. Swapping index 0 and 3 will give arr[] = [0, 0, 1, 1, 1, 1].

Input: arr[] = [0, 0, 0]
Output: -1
Explanation: No 1s are present in the array, so return -1.
*/

// =============================================================>> Solution
class Solution
{
    public:
    int minSwaps(vector<int>& arr)
    {
        int len = arr.size();
        // Corner case #1 : Empty array
        if (len == 0)
            return -1;
        // To get frequency of ones in the array
        int ones = 0;
        for(int i : arr)
        {
            ones += i;
        }
        // Corner case #2 : No 1 is present
        if (ones == 0)
            return -1;
        // Corner case #3 : Only 1 is present
        if (ones == 1 || ones == len)
            return 0;
        // Number of zeroes present
        int zeroes = len - ones;
        // Get maximum ones in a window
        int max1 = 0;
        for (int i = 0 ; i < ones ; i++)
        {
            if (arr[i] == 1)
                max1++;
        }
        int window = max1;
        for(int i = ones; i < len; i++)
        {
            // Remove element going out of the window (leftmost)
            if(arr[i - ones] == 1)
                max1--;
            // Add new element entering the window (rightmost)
            if(arr[i] == 1)
                max1++;
            window = max(max1, window);
        }
        return (ones - window);
    }
};
