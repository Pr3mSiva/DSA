#include<bits/stdc++.h>
using namespace std;

//Map takes O(N)
// int main() {
//     int n;
//     cout<<"Size:";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) {
//         cin>>arr[i];
//     }

//     map<int,int> mpp;
//     for(int i=0;i<n;i++) {
//         mpp[arr[i]]++;
//     }
//     int m;
//     cin>>m;
//     cout<<mpp[m];
//     return 0;
// }

// Unorderd Map, it should be the first preference. It has O(1) time complexity for storing and fetching and rare worst case of O(N). When we get time error then we shoud use Map. In worst case storing takes O(N) and computation takes O(N) that makes O(N^2).
int main() {
    int n;
    cout<<"Size:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++) {
        mpp[arr[i]]++;
    }
    int m;
    cin>>m;
    cout<<mpp[m];
    return 0;
}