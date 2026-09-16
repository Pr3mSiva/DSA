// LeetCode Q.No-76. Minimum Window Substring

#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

string minWindow(string s, string t) {
    if(t.size() > s.size())
        return "";

    unordered_map<char, int> required;

    for(char ch : t)
        required[ch]++;

    int left = 0;
    int right = 0;

    int count = 0;
    int minLength = INT_MAX;
    int startIndex = 0;

    unordered_map<char, int> window;

    while(right < s.size()) {
        char ch = s[right];
        window[ch]++;

        if(required.count(ch) && window[ch] <= required[ch])
            count++;

        while(count == t.size()) {
            if(right - left + 1 < minLength) {
                minLength = right - left + 1;
                startIndex = left;
            }

            char leftChar = s[left];
            window[leftChar]--;

            if(required.count(leftChar) && window[leftChar] < required[leftChar])
                count--;

            left++;
        }

        right++;
    }

    if(minLength == INT_MAX)
        return "";

    return s.substr(startIndex, minLength);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    /*
    --> We should return a window where there contains all elements of 't'
    --> It should be of minimum size
    --> The window can contain extra characters
    --> Characters in 't' can contain duplicates
    */

    string result = minWindow(s, t);

    cout << result;

    return 0;
}