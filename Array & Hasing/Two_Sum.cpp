// LeetCode Q.No-1, Two Sum

    #include<bits/stdc++.h>
    using namespace std;

    int main() {
        vector<int> vec={2,7,11,15};
        int target=18, size=vec.size(),i1,i2;

        for(int i=0;i<size;i++) {
            for(int j=i+1;j<size;j++) {
                if(vec[i]+vec[j]==target) {
                    i1=i;
                    i2=j;
                    break;
                }
            }
        }

        cout<<i1<<" "<<i2;
        return 0;
    }

// LeetCode Version
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int size=nums.size();
//         for(int i=0;i<size;i++) {
//             for(int j=i+1;j<size;j++) {
//                 if(nums[i]+nums[j] == target) {
//                     return {i,j};
//                 }
//             }
//         }
//         return{}; ----> we put return{} here because if i,j never found it will return nothing, to tell this to compiler we use this
//     }
// };