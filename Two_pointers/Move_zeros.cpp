// Leetcode Q.No- 283 Move Zeroes

#include<bits/stdc++.h>
using namespace std;

/*vector<int> moveZeroes(vector<int>& nums) {
    int n=nums.size();
    int i=0,j=n-1,front=0;
    vector<int> sol(n);
    while(i<n) {
        if(nums[i]== 0) {
            sol[j]=nums[i];
            i++;
            j--;
        }
        else if(nums[i]!=0) {
            sol[front]=nums[i];
            i++;
            front++;
        }
    }
    return sol;
}

int main() {
    vector<int> nums={0,1,0,3,12};
    vector<int> result;
    result=moveZeroes(nums);
    for(auto it=result.begin();it!=result.end();it++) {
        cout<<*(it)<<" ";
    }
    return 0;

-> this give exactly what we need to get for this problem but in leetcode version
   we have `void` as return type, we cannot use new vector to store the values
}*/

//We are using Slow-Fast pointer
void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    int slow=0,fast=0;
    for(fast=0;fast<n;fast++) {
        if(nums[fast]!=0) {
            swap(nums[slow],nums[fast]);
            slow++;
        }
    }
}

int main() {
    vector<int> nums={0,1,0,3,12};
    moveZeroes(nums);
    for(auto it=nums.begin();it!=nums.end();it++) {
        cout<<*(it)<<" ";
    }
    return 0;
}
