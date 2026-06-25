/*
Problem name : << N-Digit Numbers with Increasing Digits >>

Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).
Examples :
Input: n = 1
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: Single digit numbers are considered to be strictly increasing order.

Input: n = 2
Output: [12, 13, 14, 15, 16, 17, 18, 19, 23....79, 89]
Explanation: For n = 2, the correct sequence is 12 13 14 15 16 17 18 19 23 and so on up to 89.

Input: n = 15
Output: []
Explanation: No such number exist.
*/

// ====================================================== >> Solution

class Solution
{
    public:
    void genNum(int remDig, int currDig, int currNum, vector<int> &res)
    {
        // Required number of digits formed
        if(remDig == 0)
        {
            res.push_back(currNum);
            return;
        }
        // Choose next digits greater than current digit
        for(int next = currDig + 1 ; next < 10 ; next++)
            genNum(remDig - 1, next, currNum * 10 + next, res);
    }
    
    vector<int> increasingNumbers(int n)
    {
        vector<int> res;
        // No valid numbers
        if(n > 9)
            return res;
        // For simple 0 to 9 as single digit number
        if(n == 1)
        {
            for(int d = 0 ; d < 10 ; d++)
                res.push_back(d);
            return res;
        }
        // Always start from 1 for (n > 1)
        for(int first = 1 ; first < 10 ; first++)
            genNum(n - 1, first, first, res);
        return res;
    }
};
