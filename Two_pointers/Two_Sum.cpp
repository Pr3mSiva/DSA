// LeetCode Q.No- 167. Two Sum II - Input Array Is Sorted

#include<bits/stdc++.h>
using namespace std;

// int main() {
//     vector<int> vec= {2,7,11,15};
//     int n=vec.size();
//     int target=18, n1=0,n2=0;
//     for(int i=0;i<n;i++) {
//         for(int j=n-1;j>i;j--) {
//             if(vec[i]+vec[j]==target) {
//                 n1=i;n2=j;
//                 break;
//             }
//         }
//     }
//     cout<<n1+1<<" "<<n2+1;
//     return 0;
// }
/*
--> This takes O(N^2) time complexity but we need O(N);
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    /*
    --> we are using simple logic to reduce time
        1. target is 18
        2.left=2 and right=15, sum=17<18 so left++
        3.left=7 and right=15, sum=22>18 so right--
        4.left=7 and right=11, sum=18 found!!!
    */
    while(left < right) {
        int currentSum = numbers[left] + numbers[right];
        
        if (currentSum == target) {
            return {left + 1, right + 1}; 
        } 
        else if (currentSum < target) {
            left++; 
        } 
        else {
            right--; 
        }
    }
    return {}; 
}

int main() {
    vector<int> vec = {2, 7, 11, 15};
    int target = 18;
    
    vector<int> result = twoSum(vec, target);
    
    if(!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    }
    return 0;
}

/*
LeetCode Version
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return {left + 1, right + 1};
            }
            else if (currentSum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
*/