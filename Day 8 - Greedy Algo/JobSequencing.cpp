#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(vector<int> a, vector<int> b){
    return a[1] > b[1];
}

// Time Complexity: O(NLogN) + O(N*M).
// Space Complexity: O(M).
int JobScheduling(vector<vector<int>> jobs){
    int n = jobs.size();

    if(n==0) return 0;
    if(n==1) return jobs[0][1];

    // O(NLogN) Time.
    sort(jobs.begin(), jobs.end(), comparator);

    int time = INT_MIN;
    for(auto job: jobs){
       time = max(time, job[0]);
    }

    // O(N) space.
    vector<int> schedule(time+1, -1);

    // O(N*M) Time.
    int profit = 0;
    for(int i=0; i<n; i++){
        int j = jobs[i][0];
        while(j){
            if(schedule[j]==-1){
                schedule[j] = i;
                profit = profit + jobs[i][1];
                break;
            }
            j--;
        }
    }

    return profit;
}

int main(){
    cout << JobScheduling({{1, 12}, {3, 333}, {4, 22}, {2, 1}, {1, 34}, {2, 10}, {5, 90}});
    return 0;
}

