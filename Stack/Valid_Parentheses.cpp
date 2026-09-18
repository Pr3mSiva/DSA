// LeetCode Q.No- 20. Valid Parentheses

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    int n=s.size();
    for(int i=0;i<n;i++) {
        if(s[i] == '(' || s[i]=='{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if(st.empty()) {
                return false;
            }
            if(s[i]==')' && st.top()!='(') {
                return false;
            }
            if(s[i]=='}' && st.top()!='{') {
                return false;
            }
            if(s[i]==']' && st.top()!='[') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();//--> if we found all closing backets for the opening backets then stack will be empty and it will return 1
}

int main() {
    string s="([])";
    bool result;
    result=isValid(s);
    if(result) {
        cout<<"Valid";
    }
    else {
        cout<<"Invalid";
    }
    return 0;
}

/*
LeetCode version

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(' || s[i]=='{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) {
                    return false;
                }
                if(s[i]==')' && st.top()!='(') {
                    return false;
                }
                if(s[i]=='}' && st.top()!='{') {
                    return false;
                }
                if(s[i]==']' && st.top()!='[') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

*/