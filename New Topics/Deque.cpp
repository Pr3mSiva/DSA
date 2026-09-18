#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(30);
    dq.push_front(20);
    dq.push_front(10);
    /*
      FRONT             BACK
        ↓                ↓
        [10] [20] [30]
    */
    dq.push_back(40);
    /*
    [10] [20] [30] [40]
                    ↑
                    back
    */

    dq.pop_front(); //--> removes the front elemnt;
    dq.pop_back(); //--> removes the back element;

    //--> Unlike stack indexing is allowed

    for(int i=0;i<dq.size();i++) {
        cout<<dq[i]<<" ";
    }

    return 0;
}

/*
DEQUE STL TIME COMPLEXITIES

deque<int> dq;

dq.push_back(x);    // O(1) -> adds element to back
dq.push_front(x);  // O(1) -> adds element to front

dq.pop_back();     // O(1) -> removes element from back
dq.pop_front();    // O(1) -> removes element from front

dq.front();        // O(1) -> accesses first element
dq.back();         // O(1) -> accesses last element

dq[i];             // O(1) -> accesses element by index

dq.at(i);          // O(1) -> accesses element by index with bounds checking

dq.empty();        // O(1) -> checks whether deque is empty
dq.size();         // O(1) -> returns number of elements

dq.clear();        // O(n) -> removes all elements

IMPORTANT:
- deque supports indexing.
- deque allows insertion/removal from BOTH ends.
- deque[0] is valid.
- deque.front() gives first element.
- deque.back() gives last element.
*/