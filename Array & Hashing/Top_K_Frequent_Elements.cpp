//LeetCode Q.No-347

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums ={1,2,1,2,1,2,3,1,3,2};
    int k=2;

    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++) {
        mpp[nums[i]]++;
    }
/*-------------------------------------
    sort(mpp.begin(),mpp.end()); ---> this wont work because for this the elements should linea, but maps useses linked list
    int s=mpp.size()-1;
    for(int i=s;i>)
-------------------------------------
So we need to convert into vector/array
*/
    vector<pair<int,int>> freq;
    /*
    freq
┌─────────┬─────────┐
│ first   │ second  │
├─────────┼─────────┤
│    1    │    4    │
└─────────┴─────────┘
    */

    for(auto x : mpp) {
        freq.push_back({x.first, x.second});
        //it is simply for each iteration i calls elemnts as x and deos like this -> freq.push_back({1,4});
    }   

    //for getting top frequent elements we need to sort
    sort(freq.begin(), freq.end(),
        [](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        }
    );
    /*[](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        }
        this is a lamba function, we customize every time how ever we want for specific usees.
        --> we need to sort by .second() element. so we take two pairs as a nad b and we will compare a.second and b.second and sorts in DESC order
    */

    for(int i = 0; i < k; i++) {
        cout << freq[i].first << " ";
    }
    /*we are fetching only the .first elements as required*/
    return 0;
}

/*
--LeetCode Version--
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++) {
            mpp[nums[i]]++;
        }

        vector<pair<int,int>> freq;

        for(auto x : mpp) {
            freq.push_back({x.first, x.second});
        }

        sort(freq.begin(), freq.end(),
            [](pair<int,int> a, pair<int,int> b) {
                return a.second > b.second;
            }
        );

        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(freq[i].first);
        }
        return result;
    }
};
*/