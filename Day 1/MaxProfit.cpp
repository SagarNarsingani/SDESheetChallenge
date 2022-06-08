#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N),
// Space Complexity: O(N).
int MaxProfit(vector<int> prices){
    int n = prices.size();
    vector<int> suffix(n, 0);   // will store max price in future for each index.

    suffix[n-1] = prices[n-1];

    for(int i=n-2; i>=0; i--){
        suffix[i] = max(prices[i], suffix[i+1]);
    }

    int profit = INT_MIN;
    for(int i=0; i<n; i++){
        profit = max(profit, suffix[i]-prices[i]);
    }

    return profit;
}

int main(){
    vector<int> prices = {17, 20, 11, 9, 12, 6};
    cout << MaxProfit(prices);
}