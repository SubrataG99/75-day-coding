/*
Problem name : << Check if All Bits Set >>

Given a number n, check whether every bit in the binary representation of the given number is set or not.
Return true if yes, otherwise false.

Examples :
Input: n = 7
Output: true
Explanation: Binary for 7 is 111 all the bits are set so the output is true.

Input: n = 8
Output: false
Explanation: Binary for 8 is 1000 all the bits are not set so the output is false.

Input: n = 0
Output: false
Explanation: All the bits are 0 so the output is false.
*/

// =================================================>> Solution
class Solution
{
    public:
    bool isBitSet(int n)
    {
        // For even the last bit will always be zero
        if(n % 2 == 0)
            return false;
        // The bit change position and hence will produce zero for bitwise 'and' operation
        if((n > 0) && ((n & (n + 1)) == 0))
            return true;
        // For odd but random number
        return false;
    }
};
