// Leetcode Q.No-238 Product of Array Except Self

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> num={1,2,3,4};
    int n=num.size();
    /*
    Normal nested loops will have O(N^2), it will cause time limit so we will use orefix and suffix method in array.
    --> for the particular index in one loop we will calculate the left indices product and right indices product
    --> In the other for loop(not nested) we will find product left and right product and store it.
    */
    vector<int> leftprod(n);
    vector<int> rightprod(n);
    vector<int> result(n);
    leftprod[0] = 1;
    for(int i = 1; i < n; i++) {
        leftprod[i] = leftprod[i - 1] * num[i - 1];
    }
    rightprod[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        rightprod[i] = rightprod[i + 1] * num[i + 1];
    }
    cout << "Result: [";
    for(int i = 0; i < n; i++) {
        result[i] = leftprod[i] * rightprod[i];
        cout << result[i] <<", ";
    }
    cout << "]" << endl;

    return 0;
}