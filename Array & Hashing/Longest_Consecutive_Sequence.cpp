// LeetCode Q.No- 128, Longest Consecutive Sequence
//--> We cannot directly sort and just count becuase it take smore than O(N) time. we need only O(N) time.

#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> nums= {0,12,1,5,2,3,4,7,6};
    unordered_set<int> numset(nums.begin(),nums.end());//--> coverted the vector to set so we can calculate only for distinct numbers.
    int longest_sequence=1;
    
    if(nums.size() == 0) {
        cout << "Longest sequence length is: 0" << endl;//--> important for leetcode edge cases
        return 0;
    }

    /*
    --------Idea---------
    for a sequence we need to find the starting number. for that we will check if there is a left neighbor or not.
    like for 100 is 99 present if not then 100 is the start.
    */
   for(int num : numset) {//-->Take every element from numset, one at a time, and store it in num.
    //--> coutn() returns 1 if exists and 0 if does not exist

        if(numset.count(num - 1) == 0) {//--> this means if num -1 doesnot exist then it is the starting number.
            
            // We found a start! Begin counting.
            int currentNum = num;
            int currentStreak = 1;

            while(numset.count(currentNum + 1) == 1) {
                /*
                --> as we got the starting number no we are checking if the current_number +1 exist or not
                    if exists we will increment the current_sequence
                */
                currentNum++;
                currentStreak++;
            }

            longest_sequence = max(longest_sequence, currentStreak);//--> we update the longest_sequnce
        }
    }

    cout << "Longest sequence length is: " << longest_sequence << endl;

    return 0;
}

//LeetCode Version
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0) {
//             return 0;
//         }
//         unordered_set<int> numset(nums.begin(), nums.end());
//         int longestsequnce = 1;
//         for(int num : numset) {
//             if(numset.count(num - 1) == 0) {
//                 int currentNum = num;
//                 int currentStreak = 1;
//                 while(numset.count(currentNum + 1) == 1) {
//                     currentNum++;
//                     currentStreak++;
//                 }
//                 longestsequence = max(longestsequence, currentStreak);
//             }
//         }
//         return longestsequence;
//     }
// };