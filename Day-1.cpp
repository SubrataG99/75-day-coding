// Given the array arr[] of heights of certain buildings that lie adjacent to each other, Sunlight starts falling from the left side of the buildings. If there is a building of a certain height, all the buildings to the right side of it having lesser heights cannot see the sun.

// Find the total number of buildings that receive sunlight.

// Examples:

// Input: arr[] = [6, 2, 8, 4, 11, 13]
// Output: 4
// Explanation: Only the buildings with heights 6, 8, 11, and 13 receive sunlight; therefore, the output is 4.

// Input: arr[] = [2, 5, 1, 8, 3]
// Output: 3
// Explanation: Only buildings of height 2, 5 and 8 can see the sun, hence output is 3.

// Input: arr[] = [3, 3, 3, 1]
// Output: 3
// Explanation: The first three buildings (height 3) receive sunlight, while the last building (1) is blocked. Hence, the output is 3.

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Solution
class Solution {
  public:
    int visibleBuildings(vector<int>& arr)
    {
        int got = 0;
        int maxH = 0;
        int length = arr.size();
        for(int i=0 ; i < length ; i++)
        {
            if(arr[i] >= maxH)
            {
                maxH = arr[i];
                got++;
            }
        }
        return got;
    }
};
