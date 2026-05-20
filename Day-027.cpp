/*
Problem name : << Product Pair >>

Given an integer array arr[] and an integer target, determine whether there exists a pair of elements in the array whose product is equal to target.
Return true if such a pair exists; otherwise, return false.

Examples:
Input: arr[] = [10, 20, 9, 40], target = 400
Output: true
Explanation: As 10 * 40 = 400, the answer is true.

Input: arr[] = [-10, 20, 9, -40], target = 30
Output: false
Explanation: No pair exists with product 30.

Input: arr[] = [-10, 0, 9, -40], target = 0
Output: true
Explanation: As -10 * 0 = 0, the answer is true.
*/

// ====================================================== >> Solution
class Solution
{
    public:
    bool isProduct(vector<int> &arr, long long target)
    {
        unordered_set<int> s;
        for(int num : arr)
        {
            // For both target and num to be zero
            if ((target == 0) && (num == 0))
                return true;
            // If num is zero : division by zero is a serious criminal offense
            if(num != 0)
                if(target % num == 0)
                {
                    int next = target / num;
                    // If next is already seen
                    if(s.find(next) != s.end())
                        return true;
                    // Mark "next" as seen
                    s.insert(num);
                }
        }
        return false;
    }
};
