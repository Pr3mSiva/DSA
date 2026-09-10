// LeetCode Q.No-42 Trapping Rain Water
/*
============ " First Hard Problem " ============
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
--> This approach is wrong because i am not considering the inner terrain between the blocks
    We need to calculate according to it but i am calculating area like a rectangle, the approach from previous "Container with most water" problem
int trap(vector<int>& height) {
    int size=height.size();
    int currentH=0, mainH=0, area=0;
    for(int i=0;i<size;i++) {
        if(height[i]==0) {
            continue;
        }
        else {
            currentH=height[i];
           for(int j=i+1;j<size;j++)
        -->But this will go out of bound at i=n-1;
            {
                if(height[j]>height[i] || height[j]<height[i]) {
                    mainH=min(height[i],height[j]);
                    area+=mainH * (j-i-1);
                    break;
                }
            }
        }
    }
    return area;
}
*/
/*=======================================================================*/


/*
Example:
                a  b  c  d  e  f
    heights = {4, 2, 0, 3, 2, 5}

At a given index, the amount of water that can be stored is:
    min(left_max, right_max) - height[index]

At index 2(c):
    left_max = 4
    right_max = 5
    min(4, 5) = 4

    Water stored = 4 - height[2]
                 = 4 - 0
                 = 4 units

At index 3(d):
    left_max = 4
    right_max = 5
    min(4, 5) = 4

    But the block itself is of height 3.

    Water stored = min(left_max, right_max) - height[3]
                 = min(4, 5) - 3
                 = 1 unit
*/

int trap(vector<int>& height) {
    int n=height.size();
    int left=0,right=n-1;
    int left_max=height[left], right_max=height[right];
    int area=0;
    while(left<right) {
        if(left_max < right_max || left_max == right_max) {
            // We can do this also " if(left_max <= right_max); "
            left ++;
            left_max = max(left_max, height[left]);
            area += left_max - height[left];
        }
        else {
            right --;
            right_max = max(right_max, height[right]);
            area += right_max - height[right];
        }
    }
    return area;
}


int main() {
    vector<int> H={0,1,0,2,1,0,1,3,2,1,2,1};
    int result=trap(H);
    cout<<result;
    return 0;
}

/*
LeetCode Version-

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int left_max=height[left], right_max=height[right];
        int area=0;
        while(left<right) {
            if(left_max < right_max || left_max == right_max) {
                left ++;
                left_max = max(left_max, height[left]);
                area += left_max - height[left];
            }
            else {
                right --;
                right_max = max(right_max, height[right]);
                area += right_max - height[right];
            }
        }
        return area;
    }
};
*/