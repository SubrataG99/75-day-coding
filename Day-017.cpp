/*
Problem name : << Max Profit from Two Machines >>

Given two machines, Machine A and Machine B, and a set of n tasks. The profit earned for performing each task is given in two arrays a[] and b[] such that if Machine A performs the i-th task, the profit is a[i], and if Machine B performs it, the profit is b[i]. Machine A can process at most x tasks, and Machine B can process at most y tasks. It is guaranteed that x + y ≥ n, so all tasks can be assigned. Return the maximum possible profit after assigning each task to either Machine A or Machine B.

Examples:

Input: x = 3, y = 3, a[] = [1, 2, 3, 4, 5], b[] = [5, 4, 3, 2, 1]
Output: 21
Explanation: Machine A performs tasks with indices [2, 3, 4], and Machine B performs the rest [0, 1], giving profits (3 + 4 + 5) + (5 + 4) = 21.

Input: x = 4, y = 4, a[] = [1, 4, 3, 2, 7, 5, 9, 6], b[] = [1, 2, 3, 6, 5, 4, 9, 8]
Output: 43
Explanation: Machine A performs tasks with indices [1, 4, 5, 7], and Machine B performs the rest [0, 2, 3, 6], giving profits (4 + 7 + 5 + 6) + (1 + 3 + 6 + 9) = 41.

Input: x = 3, y = 4, a[] = [8, 7, 15, 19, 16, 16, 18], b[] = [1, 7, 15, 11, 12, 31, 9]
Output: 110
Explanation: Machine A performs tasks with indices [0, 3, 6], and Machine B performs the rest [1, 2, 4, 5], giving profits (8 + 19 + 18) + (7 + 15 + 12 + 31) = 110.
*/

// ======================================================= >>
class Solution
{
    public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        // Taking a vector of vector for priority and index
        vector<vector <int>> prior(n, vector<int>(2));
        for(int i = 0 ; i < n ; i++)
            prior[i] = {abs(a[i] - b[i]), i};
        // Sort the "prior" based on the difference so that profit can be maximized
        sort(prior.begin(), prior.end(), greater<vector<int>>());
        int profit = 0;
        int i = 0;
        // Adding profit while all the machines can work
        while((i < n) && (x > 0) && (y > 0))
        {
            // Take only the index of the priority
            int j = prior[i][1];
            // Determine which machine should take the profit to maximize
            if(a[j] > b[j])
            {
                profit = profit + a[j];
                x-- ;
            }
            else
            {
                profit = profit + b[j];
                y-- ;
            }
            i++ ;
        }
        // Only machine A is left to execute (B is finished)
        while((i < n) && (x > 0))
        {
            profit = profit + a[prior[i][1]];
            x-- ;
            i++ ;
        }
        // Only machine B is left to execute (A did its best)
        while((i < n) && (y > 0))
        {
            profit = profit + b[prior[i][1]];
            y-- ;
            i++ ;
        }
        return profit;
    }
};
