/*
Problem name : << Special Keyboard >>

Given a special keyboard that contains only four keys:
Key 1: Prints a single character 'A' on the screen.
Key 2 (Ctrl + A): Selects all the characters currently present on the screen.
Key 3 (Ctrl + C): Copies the selected characters to a buffer.
Key 4 (Ctrl + V): Pastes the content of the buffer onto the screen, appending it to the existing text.
Initially, the screen is empty and the buffer is also empty.
Determine the maximum number of 'A' characters that can be displayed on the screen after performing exactly n key presses.

Examples :

Input: n = 3
Output: 3
Explanation: With only 3 key presses, the best option is to press Key 1 each time. So, the screen shows "AAA" and the total number of A’s is 3.

Input: n = 7
Output: 9
Explanation: An optimal sequence is: press Key 1 three times to get "AAA", then use Key 2 (select all) and Key 3 (copy), followed by Key 4 twice (paste). This results in "AAAAAAAAA", so the total number of A’s is 9.
*/

// ================================================================ >> Solution
class Solution
{
    public:
    int optimalKeys(int n)
    {
        // Since we have three extra keys to press other than A, any combo less than 7 with result in <=6
        if(n < 7)
            return n;
        int screen[n];
        for (int i = 1; i <= 6; i++)
            screen[i - 1] = i;
        // For any keystroke n, calculate the maximum of:
        // 1. Pressing Ctrl-V once after copying the A's
        //    obtained by (n-3) keystrokes.
        // 2. Pressing Ctrl-V twice after copying the A's
        //    obtained by (n-4) keystrokes.
        // 3. Pressing Ctrl-V thrice after copying the A's
        //    obtained by (n-5) keystrokes.
        for(int i = 7; i <= n; i++)
            screen[i - 1] = max(2 * screen[i - 4], max(3 * screen[i - 5], 4 * screen[i -6]));
        return screen[n-1];
    }
};
