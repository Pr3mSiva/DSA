// LeetCode Q.No- 11. Container With Most Water
//--> There is ome compiler error so used individual libraries.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int left=0,right=n-1;
    int len=0,current_h=0;
    int result=0;
    while(left<right) {
        len=right-left;
        current_h=min(height[left],height[right]);
        int area=len*current_h;
        result=max(result,area);
        if(height[left]>height[right]) {
            right--;
        }
        else{
            left++;
        }
    }
    return result;
}

int main() {
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int result=maxArea(height);
    cout<<result;
    return 0;
}

/*
LeetCode Version
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int len=0,current_h=0;
        int result=0;
        while(left<right) {
            len=right-left;
            current_h=min(height[left],height[right]);
            int area=len*current_h;
            result=max(result,area);
            if(height[left]>height[right]) {
                right--;
            }
            else{
                left++;
            }
        }
        return result;
    }
};
*/