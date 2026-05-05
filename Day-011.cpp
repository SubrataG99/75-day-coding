/*
Problem name : << Palindrome Binary >>
Given an integer n, determine whether its binary representation forms a palindrome. Return true if the binary representation of n is a palindrome; otherwise, return false.

Note: A binary representation is considered a palindrome if it reads the same forward and backward.

Examples:

Input: n = 17
Output: true
Explanation: Binary representation of 17 is (10001) in binary, which reads the same forward and backward, so it is a palindrome. 

Input: n = 16
Output: false
Explanation: Binary representation of 16 is (10000) in binary, which is not a palindrome.
*/

// =================================================== >> Solution
class Solution
{
    public:
    bool isBinaryPalindrome(int n)
    {
        int rev = 0;
        int temp = n;
        while(temp > 0)
        {
            rev = (rev << 1) | (temp & 1);
            temp = temp >> 1;
        }
        return (n == rev);
    }
};
