/*
Problem name : << Elements in the Range >>
Given an array arr[] containing distinct positive integers, and two integers start and end defining a range. Determine if the array contains all elements within inclusive range [start, end].
Note: If the array contains all elements in the given range return true otherwise return false.

Examples :
Input: start = 2, end = 5, arr[] =  [1, 4, 5, 2, 7, 8, 3]
Output: true
Explanation: All integers within the range [2, 5] are 2, 3, 4, and 5, and all of them are present in the array. Therefore, the answer is true for this test case.

Input: start = 2, end = 6, arr[] = [1, 4, 5, 2, 7, 8, 3]
Output: false
Explanation: The array does not contain 6; hence, it does not contain all the elements in the range [2, 6]. Therefore, the output is false.
*/

// ====================================================>> Solution
class Solution
{
    public:
    bool checkElements(int start, int end, vector<int> &arr)
    {
        // To understand how many integers are to be searched
        int gap = end - start + 1;
        for(int i = 0 ; i < arr.size() ; i++)
            if((arr[i] >= start) && (arr[i] <= end))
                // If found, it will count as present
                gap--;
        // gap = 0 = False ; means all numbers in the range are found
        // gap > 0 = True ; means something is missing
        if(gap)
            return false;
        else
            return true;
        
    }
};
