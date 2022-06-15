#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// comparing based on the value/weight.
bool comparator(pair<int, int> a, pair<int, int> b){
    double fr1 = a.first/(double) a.second;
    double fr2 = b.first/(double) b.second;
    return fr1 > fr2;
}

// Time Complexity: O(NLogN).
// Space Complexity: O(1).
double KnapSack(vector<pair<int, int>> items, int W){
    int n = items.size();

    // O(NLogN) Time -- sorting: in decreasing order of value/weight
    sort(items.begin(), items.end(), comparator);

    double profit = 0.0;
    int weight = 0;
    int i = 0;

    // O(N) Time.
    for(int i=0; i<n; i++){
        if(weight + items[i].second <= W){
            weight = weight + items[i].second;
            profit = profit + items[i].first;
            cout << items[i].second << endl;
        } else {
            int remains = W - weight;
            cout << items[i].second << endl;
            profit = profit + (items[i].first / (double) items[i].second) * (double) remains;
            break;
        }
    }

    return profit;
}

int main(){
    cout << KnapSack({{40, 50}, {50, 40}, {25, 90}, {100, 120}, {30, 10}, {45, 200}}, 200);
    // 204.
    return 0;
}