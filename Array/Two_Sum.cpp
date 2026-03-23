// LeetCode Question-1 Two Sum


#include<iostream>
#include<vector>
using namespace std;

vector<int> twosum(vector<int>& vec, int target, int n){
   for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
         if(vec[i]+vec[j]==target) {
            return {i,j};
         }
      }
   }
   return {};
}
        
int main() {

    vector<int>vec;

    int n;
    cout<<"Enter total no.of elements: ";
    cin>>n;

    cout<<"Enter elemnts: ";
     for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        vec.push_back(temp);
     }

     int target;
     cout<<"Enter target: ";
     cin>> target;

     vector<int>vec2=twosum(vec,target,n);
     
     cout<<"["<<vec2[0]<<"],["<<vec2[1]<<"]";
     return 0;
}