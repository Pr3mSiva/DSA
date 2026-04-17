// Leetcode Q.No- 345 Reverse vowles of a string

#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
string reverseVowels(string s) {
    int n=s.size();
    int i=0, j=n-1;
    while(i<j) {
        while(i<j && !isVowel(s[i])) {
            i++; //-> if s[i] is not vowel we will move to next index from strating
        }
        while(i<j && !isVowel(s[j])) {
            j--; //-> if s[j] is not vowel we will move to next index from end
        }
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}

int main() {
    string s = "IceCreAm";
    string result=reverseVowels(s);
    cout<<result;
    return 0;
}