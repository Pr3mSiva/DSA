// LeetCode Q.No-49, Group Anagrams

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    unordered_map<string, vector<string>> anagramMap;

    int size = strs.size();
    
    for(int i = 0; i < size; i++) {
        string originalWord = strs[i];
        string sortedWord = strs[i];
        
        sort(sortedWord.begin(), sortedWord.end());
        
        anagramMap[sortedWord].push_back(originalWord);
    }

    for(auto pair : anagramMap) {
        cout << "Bucket [" << pair.first << "] contains: ";
        
        int bucketSize = pair.second.size();
        for(int j = 0; j < bucketSize; j++) {
            cout << pair.second[j] << " ";
        }
        cout << endl;
    }

    return 0;
}