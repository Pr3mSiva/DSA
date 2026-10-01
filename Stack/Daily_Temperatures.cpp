// LeetCode Q.No- 739. Daily Temperatures

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size(),0);
    stack<int> st;
    for(int i=0;i<temperatures.size();i++) {
        while(!st.empty() && temperatures[i]>temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            result[prev]=i-prev;
        }
        st.push(i);
    }
    return result;
}
/*
 --> i=0 - while() fails, st={0}
 --> i=1 - while() is valid for 1 time, prev=0, st={0} and now the result is 1-0=1
           result={1,0,0,0,0,0,0,0} and st={1}
 --> i=2 - while() is valid st={2}, result={1,1,0,0,0,0,0,0}
 --> i=3 - while() is invalid st={2,3} 
 --> i=4 - while() is invalid st={2,3,4}
 --> i=5 - while() is valid, prev=4, result[4]=5-4=1
           reult={1,1,0,0,1,0,0,0}, st={2,3}
           while() is valid again, prev=3, result[3]=5-3=2
           result={1,1,0,2,1,0,0,0}, st={2}
           while() is invalid again, result={1,1,0,2,1,0,0,0}, st={2}
 .
 .
 .

*/

int main() {
    vector<int> temperatures={73,74,75,71,69,72,76,73};
    vector<int> result;
    result=dailyTemperatures(temperatures);
    cout<<"[";
    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<", ";
    }
    cout<<"]";
    return 0;
}

/*
LeetCode Version

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> st;
        for(int i=0;i<temperatures.size();i++) {
            while(!st.empty() && temperatures[i]>temperatures[st.top()]) {
                int prev = st.top();
                st.pop();
                result[prev]=i-prev;
            }
            st.push(i);
        }
        return result;
    }
};
*/