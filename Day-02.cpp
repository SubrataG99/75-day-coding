/*
Problem Name : << Opposite Sign Pair Reduction >>

Given an array arr[] , return the final array by repeatedly apply the following operation from left to right until no more valid operations can be performed.

If two adjacent elements have opposite signs:

If their absolute values are different, remove both elements and insert the one with the greater absolute value, preserving its sign.
If their absolute values are equal, remove both elements without inserting any new element.
Examples : 

Input: arr[] = [10, -5, -8, 2, -5]
Output: [10]
Explanation: 
At Index 0 : Element 10 has positive sign.
At Index 1 : -5  has lesser absolute value than 10. Replace both of them with 10.
At Index 2 : -8  has lesser absolute value than 10. Replace both of them with 10.
At Index 3 : 2 has positive sign. So it will be in the array.
At Index 4 : -5  has greater absolute value than 2. Replace both of them with 5.
Now -5  has lesser absolute value than 10. Replace both of them with 10.

Input: arr[] = [5, -5, -2, -10]
Output: [-2, -10]
Explanation: 1st and 2nd element gets discarded because both elements have same values but opposite sign. 3rd and 4th elements have same sign. So, both will be in the array.

Input: arr[] = [-20, 1, 20]
Output: []
Explanation: 1st and 2nd elements are removed, and -20 is inserted since it has the larger absolute value. Then, the remaining elements [-20, 20] are removed (equal absolute values, opposite signs).
*/

// ========================================================================================= Solution
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr)
    {
        vector<int> stacks;
        for(int i : arr)
        {
            // If stack is not empty and next number is positive
            while((!stacks.empty()) && (i * stacks.back() < 0))
            {
                // Fetch the top of the stack (last IN)
                int top = stacks.back();
                
                // Check which one to replace
                if (abs(top) > abs(i))
                {
                    // Pop the top value of stack
                    stacks.pop_back();
                    // Keeping in single variable for simpler use
                    i = top;
                }
                else if (abs(top) < abs(i))
                {
                    stacks.pop_back();
                }
                else
                {
                    // So that the stack wont be used for same opposite vectors
                    stacks.pop_back();
                    i = 0;
                }
            }
            
            // Push the number with greater magnitude
            if (i != 0)
                stacks.push_back(i) ;
        }
        return stacks;
    }
};
