// // LeetCode Q.No-242, Valid Anagram

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s="anagram", t="nagara";
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    int s_size=s.size(),t_size=t.size(), r=0;

    if(s_size == t_size) {
            if(s == t) {
                r=1;
            }
            else  {
                r=0;
            }
    }
    else {
        r=0;
    }

    if(r==1) {
        cout<<"Anagram";
    }
    else {
        cout<<"Not anagram";
    }
    return 0; 
}

// -----LeetCode Version-----
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int s_S=s.size(),t_S=t.size();
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         if(s_S == t_S) {
//             if(s == t) {
//                 return true;
//             }
//             else {
//                 return false;
//             }
//         }
//         else {
//             return false;
//         }
//     }
// };