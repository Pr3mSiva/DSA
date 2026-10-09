#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> vec={1,2,2,2,2,3,4,5,8};

    cout<<"Vector=";
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<", ";
    }

    cout<<endl<<"Searching 4:"<<binary_search(vec.begin(),vec.end(),4)<<endl; //--> Returns 1 if exist
    cout<<"Searching 7:"<<binary_search(vec.begin(),vec.end(),7);//--> Returns 0 if not exist

    cout<<endl<<"lower_bound() of searching 2:";
    auto it=lower_bound(vec.begin(),vec.end(),2);
    cout<<it-vec.begin();//--> It gives the first index where target >= is found

    cout<<endl<<"lower_bound() of searching 7:";
    it=lower_bound(vec.begin(),vec.end(),7);
    cout<<it-vec.begin();//--> As 7 does not exist it gives us the first greatest number 8

    cout<<endl<<"upper-bound() of searching 2:";
    it=upper_bound(vec.begin(),vec.end(),3);
    cout<<it-vec.begin();//--> Gives strictly the first grester number than the target
    return 0;
}