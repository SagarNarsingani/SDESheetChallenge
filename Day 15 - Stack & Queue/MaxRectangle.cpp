#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Finding indeces of next smaller histogram in left side.
// O(N) time.
// O(N) space.
vector<int> nextSmallerLeft(vector<int> heights, int n){
    stack<int> s;
    vector<int> dist(n, -1);
    s.push(n-1);
    for(int i=n-2; i>=0; i--){
        int curr = heights[i], top = heights[s.top()];
        while(!s.empty() and curr < top){
            dist[s.top()] = i;
            s.pop();
            if(!s.empty()) top = heights[s.top()];
        }
        s.push(i);
    }
    return dist;
}

// Finding indeces of next smaller histogram in Right side.
// O(N) time.
// O(N) space.
vector<int> nextSmallerRight(vector<int> heights, int n){
    stack<int> s;
    vector<int> dist(n, n);
    s.push(0);
    for(int i=1; i<n; i++){
        int curr = heights[i], top = heights[s.top()];
        while(!s.empty() and curr < top){
            dist[s.top()] = i;
            s.pop();
            if(!s.empty()) top = heights[s.top()];
        }
        s.push(i);
    }

    return dist;
}

// Time Complexity: O(3*N) ~ O(N).
// Space Complexity: O(4*N) ~ O(N).
int getMaxRectArea(vector<int> heights){
    int n = heights.size();

    vector<int> left = nextSmallerLeft(heights, n);
    vector<int> right = nextSmallerRight(heights, n);

    int maxArea = INT_MIN;
    for(int i=0; i<n; i++){
        int curr = (abs(left[i] - right[i])-1) * heights[i];
        maxArea = max(curr, maxArea);
    }

    return maxArea;

}

int main(){
    cout << getMaxRectArea({6, 1, 8, 10, 5, 7, 0, 4, 5, 8 });
    return 0;
}