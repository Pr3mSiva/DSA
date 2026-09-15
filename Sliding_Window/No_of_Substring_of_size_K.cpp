//LeetCode Q.No- 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

#include<iostream>
#include<vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int n=arr.size();
    int result=0;
    int left=0,right=left+k-1;
    int current_result=0,sum=0;
    //--> We dont require current result becuase sum/k >= threshold so, sum >= threshold*k;
    for(int i=0;i<=right;i++) {
        sum+=arr[i];
    }
    // current_result=sum/k;
    while(right<n) {
        if(sum>=threshold*k) {
            result++;
        }
        right++;
        if(right<n) {
            sum=sum-arr[left]+arr[right];
        }
        left++;
    }
    return result;
}

int main() {
    vector<int> arr= {11,13,17,23,29,31,7,5,2,3};
    int k=3, threshold=5;
    int result=numOfSubarrays(arr,k,threshold);
    cout<<result;
    return 0;
}

/*
LeetCode Version

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int result=0;
        int left=0,right=left+k-1;
        int sum=0;
        for(int i=0;i<=right;i++) {
            sum+=arr[i];
        }
        while(right<n) {
            if(sum>=threshold * k) {
                result++;
            }
            right++;
            if(right<n) {
                sum=sum-arr[left]+arr[right];
            }
            left++;
        }
        return result;
    }
};
*/