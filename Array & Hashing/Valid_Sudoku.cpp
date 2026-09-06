// LeetCOde Q.No- 36. Valid Sudoku

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> board = 
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};
     /*
    --> there should be 1 to 9 with no repition in both row and column
    --> there should be 1 to 9 in every 3X3 box
    */
    
    unordered_set<char> rows[9];
    unordered_set<char> cols[9];
    unordered_set<char> boxes[9];
    /*
    we created set of 9set of boxes
    ┌─────────┬─────────┬─────────┐
    │ box 0   │ box 1   │ box 2   │
    ├─────────┼─────────┼─────────┤
    │ box 3   │ box 4   │ box 5   │
    ├─────────┼─────────┼─────────┤
    │ box 6   │ box 7   │ box 8   │
    └─────────┴─────────┴─────────┘
    */

    for(int r=0;r<9;r++) {
        for(int c=0;c<9;c++) {
            if (board[r][c]== '.') {
                continue;
            }

            char current_value=board[r][c];
            int box_index = (r / 3) * 3 + (c / 3);
            /*
            -->(r/c)/3 give int value
            now for r=4 and c=7
            -->(4/3) =1*3=3 and (7/3)=2
               3+2 is 5, so r=4 and c=7 belongs to box 5
            */
            if (rows[r].count(current_value) || cols[c].count(current_value) || boxes[box_index].count(current_value)) {
                //--> count() checks the entire row/col,box for current_value if it is present or not and return 1 if present.
                cout << "Invalid Sudoku!" << endl;
                return 0;
            }
            else {
                rows[r].insert(current_value);
                 cols[c].insert(current_value);
                 boxes[box_index].insert(current_value);
            }
        }
    }
    cout<<"Valid Sudoku";
    return 0;
}

/*
For every cell:

       ↓

Is it '.'?
       │
       ├── YES → Skip it
       │
       ↓ NO

Find its box number

       ↓

Check:
┌──────────────────────────┐
│ Is value already in row? │
│ Is value already in col? │
│ Is value already in box? │
└──────────────────────────┘
          │
          ├── YES → INVALID → STOP
          │
          ↓ NO

Add value to:
    ↓
 row set
 column set
 box set

       ↓

Go to next cell
*/

//LeetCOde Veresion

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
        
//         unordered_set<char> rows[9];
//         unordered_set<char> cols[9];
//         unordered_set<char> boxes[9];

//         for(int r = 0; r < 9; r++) {
//             for(int c = 0; c < 9; c++) {
                
//                 if(board[r][c] == '.') {
//                     continue;
//                 }

//                 char current_value = board[r][c];

//                 int box_index = (r / 3) * 3 + (c / 3);

//                 if(rows[r].count(current_value) ||
//                    cols[c].count(current_value) ||
//                    boxes[box_index].count(current_value)) {
                    
//                     return false;
//                 }
//                 else {
//                     rows[r].insert(current_value);
//                     cols[c].insert(current_value);
//                     boxes[box_index].insert(current_value);
//                 }
//             }
//         }

//         return true;
//     }
// };