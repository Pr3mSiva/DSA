//LeetCode Q.no-271, Premium question solved in NeetCode150

#include<bits/stdc++.h>
using namespace std;

string encode(vector<string>& strs) {
    string encodedString = "";
    for (int i = 0; i < strs.size(); i++) {
        // Prepend length, add the '#' delimiter, then the actual word
        encodedString += to_string(strs[i].size()) + "#" + strs[i];
    }
    return encodedString;
}

vector<string> decode(string s) {
    vector<string> decodedStrings;
    int i = 0; // The main pointer scanning through the string
    
    while (i < s.size()) {
        // 1. Find the delimiter
        int j = i;
        while (s[j] != '#') {
            j++;
        }
        
        // 2. Extract the length integer
        int wordLength = stoi(s.substr(i, j - i));
        
        // 3. Extract the actual word
        string word = s.substr(j + 1, wordLength);
        decodedStrings.push_back(word);
        
        // 4. Move the main pointer to the start of the next block
        i = j + 1 + wordLength;
    }
    return decodedStrings;
}

int main() {
    // Create a test case
    vector<string> original = {"neet", "code", "love", "you"};
    
    cout << "Original Array: ";
    for (int i = 0; i < original.size(); i++) {
        cout << "[" << original[i] << "] ";
    }
    cout << "\n-----------------------------------\n";

    // Run the Encode function directly
    string encoded = encode(original);
    cout << "Encoded String: " << encoded << "\n";
    cout << "-----------------------------------\n";

    // Run the Decode function directly
    vector<string> decoded = decode(encoded);
    cout << "Decoded Array:  ";
    for (int i = 0; i < decoded.size(); i++) {
        cout << "[" << decoded[i] << "] ";
    }
    cout << endl;

    return 0;
}
