// LeetCode Q.No- 121. Best Time to Buy and Sell Stock
/*
-->Here the sliding window has no fixed size k, if will increase or decrease dynamically on the condition
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int left=0,right=left+1;
    int profit=0;
    while(right<n) {
        if(prices[left]>prices[right]) {
            /*
            --> If we can buy a stock at low price tomorrow why to buy today, so we move to next lower price.
            */
            left=right;//--> when ever we find a new lower price at right we will directly shift the left to new lower price found at right
            right++;
        }
        else{
            int current_profit=prices[right]-prices[left];
            right++;
            profit=max(profit,current_profit);
        }
    }
    return profit;
}

int main() {
    vector<int> price={5, 1, 2, 0, 4};
    int profit=maxProfit(price);
    cout<<profit;
    return 0;
}

/*
LeetCode version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int left=0,right=left+1;
        int profit=0;
        while(right<n) {
            if(prices[left]>prices[right]) {
                left=right;
                right++;
            }
            else{
                int current_profit=prices[right]-prices[left];
                right++;
                profit=max(profit,current_profit);
            }
        }
        return profit;
    }
};
*/