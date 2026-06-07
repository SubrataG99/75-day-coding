/*
Problem name : << Finding Profession >>

Consider a special family of Engineers and Doctors with following rules :
Everybody has two children.
First child of an Engineer is an Engineer and second child is a Doctor.
First child of an Doctor is Doctor and second child is an Engineer.
All generations of Doctors and Engineers start with Engineer.

Given level and position (pos) of a person in above ancestor tree, find profession of the person.

Examples:
Input: level = 4, pos = 2
Output: Doctor
Explaination: It is shown in the tree given in question.

Input: level = 3, pos = 4
Output: Engineer
Explaination: Already given in the tree in question.
*/

// =====================================================> Solution
class Solution
{
    public:
    string profession(int level, int pos)
    {
        int count = 0;
        int n = pos-1;
        while(n)
        {
            n = n & (n - 1);
            count++;
        }
        return (count % 2) ? "Doctor" : "Engineer";
    }
};

// Working...
// Let us encode Engineer as 0 and Doctor as 1.
// First child keeps the same value and second child flips (complements) the it.
// Let us write (pos - 1) in binary. Each bit tells the path from the root: 0 -> first child (no flip) and 1 -> second child (flip)
// Therefore, even number of flips -> still Engineer (0) and odd number of flips -> Doctor (1)
// That is why the answer depends on the parity of set bits.
