// LeetCode Q.no- 84. Largest Rectangle in Histogram


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > currHeight) {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }

            int area = height * width;
            maxArea = max(maxArea, area);
        }

        st.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = largestRectangleArea(heights);
    cout << "Largest area = " << result;

    return 0;
}

/*
Leetcode Version
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currHeight) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};
*/