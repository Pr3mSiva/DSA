#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//--> Stack follow - Last In First Out

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.top(); //--> returns top element in the stack = 30

    st.pop(); //--> removes the top element = 30

    st.empty(); //--> if stack is empty returns 1 if not return 0

    /*
    --> We cannot access by index like st[1], we have only access to top() only
        |
        -->We can not use direct normal for loops as indexing is not allowed so we use

    while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
    }

    --> But this pop() elements of the original stack, to just iterate through the stack we can make a temp stack
    */
   
    stack<int> temp = st;

    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}
/*
STACK STL TIME COMPLEXITIES

stack<int> st;

st.push(x);     // O(1) -> adds element to top
st.pop();       // O(1) -> removes top element
st.top();       // O(1) -> accesses top element
st.empty();     // O(1) -> checks whether stack is empty
st.size();      // O(1) -> returns number of elements

IMPORTANT:
- stack does NOT support indexing.
- st[0] is invalid.
- st.top() gives access to only the top element.
*/