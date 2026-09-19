// LeetCode Q.No- 150. Evaluate Reverse Polish Notation

/*
Revesrse Polish Notation

S={"2","1","+","3","*"};
--> It is simple, if we get number we will continue and if we come accross any operator we will perform in between it

2-->1-->+ => 2+1=3

S={"3","3","*"}
3-->3-->* => 3*3=9
S={"9"};
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for(int i=0;i<tokens.size();i++) {
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
            int n1,n2;
            n1=nums.top();
            nums.pop();
            n2=nums.top();
            nums.pop();
            if(tokens[i]=="+") {
                nums.push(n2+n1);
            }
            if(tokens[i]=="-") {
                nums.push(n2-n1);
            }
            if(tokens[i]=="*") {
                nums.push(n2*n1);
            }
            if(tokens[i]=="/") {
                nums.push(n2/n1);
            }
        }
        else {
            nums.push(stoi(tokens[i])); //--> stoi() coverts string to int
        }
    }
    return nums.top();
}
/*
--> We are storing all numbers untill we get a operator and when we come across a operator we are pop() 2 top elemnts and then we applying the operation and again pushing into the stack and continuing
*/

int main() {
    vector<string> tokens={"2","1","+","3","*"};
    int result=evalRPN(tokens);
    cout<<result;
    return 0;
}

/*
LeetCode Version

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="+" || tokens[i]=="-" || 
                tokens[i]=="*" || tokens[i]=="/") {
                    int n1,n2;
                    n1=nums.top();
                    nums.pop();
                    n2=nums.top();
                    nums.pop();
                    if(tokens[i]=="+") {
                        nums.push(n2+n1);
                    }
                    if(tokens[i]=="-") {
                        nums.push(n2-n1);
                    }
                    if(tokens[i]=="*") {
                        nums.push(n2*n1);
                    }
                    if(tokens[i]=="/") {
                        nums.push(n2/n1);
                    }
            }
            else {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};

*/