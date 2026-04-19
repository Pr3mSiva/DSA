// Leetcode Q.no 11- Container With Most Water
/*
Dont't fix a pointer at the max height because the area does not only depend on height
if height is max and width is min, the area will not be max. So find max of both

-> Many question can be solved using tow pointers one at begining and one at end

*/
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int i=0,j=n-1;
    int area=(min(height[i],height[j]))*(j-i); //->min() finds the min height and (j-i) give width, j-i becoz j is bigger
    int current_area;
    while(i<j) {
        current_area=(min(height[i],height[j]))*(j-i);
        if(current_area>area) {
            area=current_area;
        }
        if(height[i]>height[j]) {
            j--; //->if value of height[i]>height[j], we need walls with max height so we move j--
        }
        else{
            i++; //->vice-versa of above one
        }
    }
    return area;
}

int main() {
    vector<int> vec={1,8,6,2,5,4,8,3,7};
    int result;
    result=maxArea(vec);
    cout<<result;
    return 0;
}