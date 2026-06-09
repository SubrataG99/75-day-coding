/*
Problem name : << Seating Arrangement >>
Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.
Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).

Examples:
Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.

Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.
*/

// ===============================================> Solution
class Solution
{
    public:
    bool canSeatAllPeople(int k, vector<int> &seats)
    {
        int n = seats.size();
        // Check if adjacent seats are already occupied
        for(int i = 1 ; i < n ; i++)
            if(seats[i] == seats[i - 1] && seats[i - 1] == 1)
                return false;
        // Iterate through the seats
        for(int i = 0 ; i < seats.size() ; i++)
        {
            int prev = (i == 0) ? 0 : seats[i - 1];
            int next = (i == n-1) ? 0 : seats[i + 1];
            // If all adjacent seats are empty
            if((prev + next + seats[i]) == 0)
            {
                k--;
                // Skip the next to keep the adjacent empty
                i++;
            }
        }
        return (k < 1);
    }
};
