#include <iostream>
#include <vector>
using namespace std;

int MinimumCoins(int amt){
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0, i=0;
    while(amt){
        while(amt-coins[i] >= 0){
            amt = amt - coins[i];
            ans++;
        }
        i++;
    }

    return ans;
}

int main(){

    cout << MinimumCoins(50);
    return 0;
}