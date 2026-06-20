/*
Problem name : << Last Digit of a^b >>

Given two integers a and b in the form of strings. Return the last digit of ab.
Examples:
Input: a = "3", b = "10"
Output: 9
Explanation: 3^10 = 59049. Last digit is 9.

Input: a = "6", b = "2"
Output: 6
Explanation: 6^2 = 36. Last digit is 6.
*/

// ==================================================== >> Solution
class Solution
{
    public:
    int modulo(int d, string &b)
    {
        int mod = 0;
        for(int i = 0 ; i < b.length() ; i++)
            mod = (mod * 10 + b[i] - '0') % d;
        return mod;
    }
    
    int getLastDigit(string& a, string& b)
    {
        int n = a.length();
        int m = b.length();
        if((m == 1) && (b[0] == '0'))
            return 1;
        if((n == 1) && (a[0]  == '0'))
            return 0;
        int exp = (modulo(4, b) == 0) ? 4 : modulo(4, b);
        int res = pow(a[n - 1] - '0', exp);
        return res % 10;
    }
};
