// LeetCode Q.no - 155. Min Stack

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
stack<int> st;
stack<int> minst;
    MinStack() {

    }
    
    void push(int value) {
        st.push(value);
        if(minst.empty()) {
            minst.push(value);
        }
        else {
            minst.push(min(value,minst.top()));
            /*
            --> In minst(), first we kept -2, then we push() 0, now we will check min(0,-2) and -2 is min so it will be pushed to minst()
                |
                --> minst= {-2,-2} so always the top() of minst will be minimum only and all of these takes O(1);
            */
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};


int main() {
    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << st.getMin() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.getMin() << endl;

    return 0;
}

/*
LeetCode Version

class MinStack {
public:
    stack<int> st,minst;
    MinStack() {
    
    }

    void push(value) {
        st.push(value);
        if(minst.empty()) {
            minst.push(value);
        }
        else {
            minst.push(min(value,minst.top()));
        }
    }

    void pop() {
        st.pop();
        minst.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }
};
*/