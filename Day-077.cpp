/*
Problem name : << Count Pairs Divisible By K >>

Given an array arr[] and positive integer k, count total number of pairs in the array whose sum is divisible by k.

Examples:
Input :  arr[] = [2, 2, 1, 7, 5, 3], k = 4
Output : 5
Explanation : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3).

Input : arr[] = [5, 9, 36, 74, 52, 31, 42], k = 3
Output : 7 
Explanation : There are seven pairs whose sum is divisible by 3, i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), (31, 5) and (5, 52).
*/

// ================================================= >> Solution
class Solution
{
    public:
    int countKdivPairs(vector<int>& arr, int k)
    {
        // Create a frequency array to count occurrences of all remainders when divided by k
        vector<int> freq(k, 0);
        // Count occurence of all remainders
        for(int i = 0 ; i < arr.size() ; i++)
            ++freq[arr[i] % k];
        // If both pairs are divisible by 'k'
        int res = freq[0] * (freq[0] - 1) / 2;
        // count for all i and (k-i) freq pairs
        for(int i = 1 ; i <= k/2 && i != (k - i) ; i++)
            res = res + freq[i] * freq[k - i];
        // if k is even
        if(k % 2 == 0)
            res = res + (freq[k/2] * (freq[k/2] - 1) / 2) ;
        return res;
    }
};
