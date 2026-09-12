// LeetCode Q.No- 3. Longest Substring Without Repeating Characters

#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n=s.size();
    int left=0;
    // int right=left+1; --> By this when ever we have single character at index 0 we will skip it
    // --> and as right starts from 1 in set at index 0 we will not give anything that creates compilation error
    int right=0;
    int result=0;
    unordered_set<char> memory;
    while(right<n) {
        if(memory.count(s[right])==0){
            memory.insert(s[right]);
            /*
            --> we are checking at index 0 in memory set does s[right] exist or not
            -->.count() gives 1 if exist and 0 for not exist
            |
            -->.insert() insert the non duplicate character in to the memory set
            */
            int current_result=(right-left)+1;
            result=max(result,current_result);
            right++;
        }
        else {
            memory.erase(s[left]);
            //--> .erase() erases the character from the memory set
            left++;
        }
    }
    return result;
}

int main() {
    string s="abcdefghijklmnopqrstuvwxyz";
    int result=lengthOfLongestSubstring(s);
    cout<<result;
    return 0;
}

/*
LeetCode Version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int result=0;
        unordered_set<char> memory;
        while(right<n) {
            if(memory.count(s[right])==0){
                memory.insert(s[right]);
                int current_result=(right-left)+1;
                result=max(result,current_result);
                right++;
            }
            else {
                memory.erase(s[left]);
                left++;
            }
        }
        return result;
    }
};

*/