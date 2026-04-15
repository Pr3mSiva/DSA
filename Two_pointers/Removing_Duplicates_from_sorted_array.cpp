// LeetCode Question-26 Removing duplicates from sorted array

/*I am using two pointer method to solve this
  comapring the values and updating nums[i] with j*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++) {
            if(nums[i]!=nums[j]) {
                nums[++i]=nums[j];
            }
        }
        return i+1;
    }
};