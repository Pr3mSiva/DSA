// LeetCode Q.No- 643. Maximum Average Subarray I

#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    int left=0,right=k-1;
    double result=0;
    // int sum=0; --> as our k is already int if we do int/int we get int only so if we give sum as double we will get a decimal answer
    double sum=0;
    for(int i=0;i<=right;i++) {
        sum+=nums[i];
    }
    result=sum/k;
    while(right<n-1) {
        left++;
        right++;
        sum=sum+nums[right]-nums[left-1];
        double avg=sum/k;
        result=max(result,avg);
    }
    return result;
}

int main() {
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    double result=findMaxAverage(nums,k);
    cout<<result;
    return 0;
}

/*
LeetCode Version
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=k-1;
        double result=0;
        double sum=0;
        for(int i=0;i<=right;i++) {
            sum+=nums[i];
        }
        result=sum/k;
        while(right<n-1) {
            left++;
            right++;
            sum=sum+nums[right]-nums[left-1];
            double avg=sum/k;
            result=max(result,avg);
        }
        return result;
    }
};
*/