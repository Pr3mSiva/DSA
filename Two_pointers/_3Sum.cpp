// Leetcode Q.no- 15. 3Sum

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int fix=0;
    vector<vector<int>> result;//--> The result is a 2d vector
    for(int i=0;i<n;i++) {
        int  left=i+1, right=n-1;
        if(i>0 && nums[i]==nums[i-1]) {
            /*
            -->to avoid dulpicate checking of numbers we are checking and i>0 is stop going out of bound. Like if i=0 and i-1 will out of bound to stop it we added this condition.
            */
            continue;
        }
        while(left<right) {
            if(nums[i]+nums[left]+nums[right]==0) {
                result.push_back({nums[i],nums[left],nums[right]});
                left++;
                while(left<right && nums[left]==nums[left-1]) {
                    /*
                    --> Same here to avoid duplicates
                    */
                    left++;
                    continue;
                }
            }
            else if(nums[i]+nums[left]+nums[right]<0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> vec={-1,0,1,2,-1,-4};
    vector<vector<int>> result=threeSum(vec);
    int n=result.size();
    for(int i=0;i<n;i++) {
        cout<<"[ ";
        for(int j=0;j<result[i].size();j++) {
        cout<<result[i][j]<<" ";
        }
        cout<<"], ";
    }
    return 0;
}

/*
LeetCode Version
Class Solution{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int fix=0;
        vector<vector<int>> result;//--> The result is a 2d vector
        for(int i=0;i<n;i++) {
            int  left=i+1, right=n-1;
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            while(left<right) {
                if(nums[i]+nums[left]+nums[right]==0) {
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(left<right && nums[left]==nums[left-1]) {
                        left++;
                        continue;
                    }
                }
                else if(nums[i]+nums[left]+nums[right]<0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};
*/