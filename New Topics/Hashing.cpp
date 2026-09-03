// We create a extra hash array initialy initialized to 0, when ever a number/character comes we just increment the counter
#include<bits/stdc++.h>
using namespace std;

// Number counter/Hashing

// int main() {
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++) {
//         cin>>array[i];
//     }

//     // Hash function/ table
//     int hash[13]={0};
//     for(int i=0;i<n;i++) {
//         hash[array[i]]+=1; 
//         // This creates a array of 0, when ever array[i] is 1 it will increase the counter and continues for other numbers
//     }

//     int number;
//     cin>>number;
//     cout<<hash[number];
//     return 0;

// }

// Character Hashing

int main() {
    string c;
    cin>>c;

    //Hash
    int hash[257]={0};
    for(int i=0;i<c.size();i++) {
        hash[c[i]]+=1;
    }

    char s;
    cin>>s;
    cout<<hash[s];
    return 0;
}