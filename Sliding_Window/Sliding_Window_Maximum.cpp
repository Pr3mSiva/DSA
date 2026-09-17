// LeetCode Q.No- 239. Sliding Window Maximum

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

/*
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> result(n-k+1);
    int left=0,right=left+k-1;
    vector<int> current_vec;
    for(int i=0;i<=right;i++) {
        current_vec.push_back(nums[i]);
    }
    while(right<n) {
        result[left]=*max_element(current_vec.begin(),current_vec.end());
        if(right==n-1) {
            break;
        }
        right++;
        current_vec.erase(current_vec.begin());
        current_vec.push_back(nums[right]);
        left++;
    }
    return result;
}

--> It works perfectly fine for small examples and llokes like the loop is running for n times and the time complexity is O(n)
--> But in each loop we are checking for max element which checks each elemnt in current_vec of size K so , this makes up to O(NK)
--> The actuall time complexity is not O(N) it is O(NK) --> LeetCode throwing Time Limit Exceeded error

*/
/*
--> multiset can have duplicates also and automatically stores in sorted way by taking O(log n) time complexity

In set

set<int> s;
s.insert(5);
s.insert(5);
s.insert(3);

Output -- {3, 5}

In multiset

multiset<int> s;
s.insert(5);
s.insert(5);
s.insert(3);

Output -- {3, 5, 5} also sorted
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> result;
    multiset<int> window;
    for(int i=0;i<k;i++) {
        window.insert(nums[i]);
    }
    result.push_back(*window.rbegin());
    /*
    --> window.begin() give the first element and window.rbegin() give the last element, in this case which is amx element of the current window.
    */
    for(int right=k;right<n;right++) {
        window.erase(window.find(nums[right-k]));//--> We are erasing only the first element without finding anythin so it is O(1)
        window.insert(nums[right]);
        result.push_back(*window.rbegin());
    }
    return result;
}
/*
--> There is more better way to solve this using "dqueue", need to learn using it.
*/

int main() {
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    int n=nums.size();
    vector<int> result=maxSlidingWindow(nums,k);   
    cout<<"[";
    for(int i=0;i<n-k+1;i++) {
        cout<<result[i]<<", ";
    }
    cout<<"]";
    return 0;
}

/*
LeetCode version
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result;
        multiset<int> window;
        for(int i=0;i<k;i++) {
            window.insert(nums[i]);
        }
        result.push_back(*window.rbegin());
        for(int right=k;right<n;right++) {
            window.erase(window.find(nums[right-k]));
            window.insert(nums[right]);
            result.push_back(*window.rbegin());
        }
        return result;
    }
};
*/