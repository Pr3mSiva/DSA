// Leetcode problem 125: Valid Palindrome

/*
while(i<j &&!isalnum(s[i])) {
    i++;
}
while(i<j &&!isalnum(s[j])) {
    j--;
}
->we skip both i and j until we get isalnum() in both i and j, then we
compare for palindrome
->if s[0]=' ';
 we skip it by i++;
 now we compare s[1] and s[4] {i=1,j=4}
*/
 #include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j) {
            while(i<j &&!isalnum(s[i])) {
                i++;
            }
            while(i<j &&!isalnum(s[j])) {
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

int main() {
    string s="Race a car";
    if(isPalindrome(s)) {
        cout<<"Palindrome";
    }
    else {
        cout<<"Not a palindrome";
    }
    return 0;
}