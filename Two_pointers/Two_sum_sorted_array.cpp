// Leetcode Q.No- 167 Two Sum II - Input Array Is Sorted

#include<bits/stdc++.h>
using namespace std;

/*vector<int> twoSum(vector<int>& numbers, int target) {
    int n=(numbers.size())-1;
    int i=0,j=0;
    vector<int> solution;
    while(i<=n) {
        while(j<=n) {
            if(numbers[i] + numbers[j]== target) {
                solution={i+1,j+1};
            }
            j++;
        }
        i++;
        j=i+1;  -> I re-initialized j to i+1 beacuase after 1st iteration j will be remain 3 forever, after that we
                    will always add nums[i] with nums[j=3]
    }
    return solution;
} */ //->this is also correct but it takes too much time, Time Limit error  

// Leetcode Q.No- 167 Two Sum II - Input Array Is Sorted

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0; 
    int j = numbers.size() - 1; 
    while (i < j) {
        int current_sum = numbers[i] + numbers[j];
        
        if (current_sum == target) {
            return {i + 1, j + 1};
        } 
        else if (current_sum < target) {
            i++; // Sum is small, moving i forward
        } 
        else {
            j--; // Sum is too big, moving j backward
        }
    }
    return {};
}

int main() {
    vector<int> vec = {2, 7, 11, 15};
    vector<int> result = twoSum(vec, 18);
    
    for(auto it = result.begin(); it != result.end(); it++) {
        cout << *(it) << " ";
    }
    return 0;
}
