// Leetcode question 977- Squares of a sorted array

/*
->after comparing to store new squared values i created new vec num
->after squaring, I kept the largest value at right side end
->if nums[i] wins I did i++, not j-- becuase we need to compare it with next nums[i] and same for nums[j] 
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    int n=nums.size();
    vector<int> num(n);
    int i=0,j=n-1,k=n-1;
    while(i<=j) {
        if(nums[i]*nums[i] > nums[j]*nums[j]) {
             num[k]=nums[i]*nums[i];
            i++;
            k--;
        }
        else{
            num[k]=nums[j]*nums[j];
            j--;
            k--;
        }
    }
    return num;
}

int main() {
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result= sortedSquares(nums);
    cout<<"{";
    for(auto it=result.begin();it!=result.end();it++) {
        cout<<*(it)<<", ";
    }
    cout<<"}";
    return 0;
}