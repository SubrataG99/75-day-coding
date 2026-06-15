/*
Problem name : << Minimum Cost to Fill Given Weight >>

Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[], find the minimum total cost to buy exactly w kg oranges
The cost of 1 kg orange is present at index 0 and in general arr[i] has cost of (i+1) kg orange.
cost[i] = -1 means that 'i+1' kg packet of orange is unavailable.
If it is not possible to buy exactly w kg oranges then return -1. It may be assumed that there is an infinite supply of all available packet types.

Examples:
Input: cost[] = [20, 10, 4, 50, 100], w = 5
Output: 14
Explanation: The minimum cost is 14 by purchasing a 2kg packet for 10 and a 3kg packet for 4.

Input: cost[] = [-1, -1, 4, 3, -1], w = 5
Output: -1
Explanation: It is not possible to buy 5 kgs.
*/

// =====================================================> Solution
class Solution
{
    public:
    int minimumCost(vector<int> &cost, int w)
    {
        // val[] and wt[] arrays
        // val[] array to store cost of 'i' kg packet of orange
        // wt[] array weight of packet of orange
        vector<int> val, wt;
        int n = cost.size();
        // traverse the original cost[] array and skip
        // unavailable packets and make val[] and wt[]
        // array. size variable tells the available number
        // of distinct weighted packets
        for(int i = 0 ; i < n ; i++)
        {
            if(cost[i] != -1)
            {
                val.push_back(cost[i]);
                wt.push_back(i + 1);
            }
        }
        int size = val.size();
        const int inf = 1e9;
        // DP table
        vector<vector<int>> minCost(size + 1, vector<int>(w + 1, inf));
        // fill 0th column with 0
        for(int i = 0 ; i <= size ; i++)
            minCost[i][0] = 0;
        // now check for each weight one by one and fill the
        // matrix according to the condition
        for(int i = 1; i <= size; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                // wt[i-1] > j means capacity of bag is less than weight of item
                if(wt[i - 1] > j)
                    minCost[i][j] = minCost[i - 1][j];
                // here we check we get minimum cost either by including it or excluding it
                else
                    minCost[i][j] = min(minCost[i - 1][j], minCost[i][j -wt[i - 1]] + val[i - 1]);
            }
        }
        // exactly weight 'w' can not be made by given weights
        return (minCost[size][w] >= inf) ? -1 : minCost[size][w];
    }
};
