// LeetCode Q.No- 704 Binary Search

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search(vector<int>& nums, int target) {
    if(binary_search(nums.begin(),nums.end(),target)) {
        int result;
        auto it=lower_bound(nums.begin(),nums.end(),target);
        result=it-nums.begin();
        return result;
    }
    else {
        return -1;
    }
}

int main() {
    vector<int> vec={-1,0,3,5,9,12};
    int target=91;
    int result=search(vec,target);
    cout<<result;
    return 0;
}

/*
Leet Code version
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)) {
            auto it=lower_bound(nums.begin(),nums.end(),target);
            return it-nums.begin();
        }
        else {
            return -1;
        }
    }
};
*/