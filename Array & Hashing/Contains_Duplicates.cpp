// LeetCode Q.No217 Contains Duplicates

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> num={1,2,3,4,5,1};
//     int size=num.size();
//     int r;

//     for (int i=0; i<size;i++) {
//         for(int j=i+1;j<size;j++) {
//             if(num[i]==num[j]) {
//                 r= 1;
//             }
//         }
//     }

//     if(r==1) {
//         cout<<"True";
//     }
//     else {
//         cout<<"False";
//     }

//     return 0;
// }
//--> this code works but it is brute force method and takes O(n^2) time


#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> num={5,4,3,2,1,5};
    sort(num.begin(),num.end());
    int size=num.size();
    int r=0;

    for(int i=0;i<size-1;i++) { //size-1 because not to go out of bound
        if(num[i]==num[i+1]) {
            r=1;
        }
    }

    if(r==1) {
        cout<<"True";
    }
    else {
        cout<<"False";
    }

    return 0;
}

//LeetCode version
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int size=nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<size-1;i++) {
//             if(nums[i]==nums[i+1]) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };