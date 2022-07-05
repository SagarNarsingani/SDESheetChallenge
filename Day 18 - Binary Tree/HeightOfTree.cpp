#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Tree.h"
using namespace std;

unordered_map<int, int> pos;

int GetHeight(vector<int> in, vector<int> level, int &height, int s, int e, int n){
    if(s>e)
        return 0;
    
    int index=-1;
    if(pos.find(level[0])!=pos.end()){
        index = pos[level[0]];
    }

    if(index==-1)
        return 0;
    
    int left = index-s;
    int right = e-index;

    vector<int> leftLevel;
    vector<int> rightLevel;

    for(int i=0; i<n; i++){
        if(pos[level[i]]<index){
            leftLevel.push_back(level[i]);
        }
    }

    for(int i=0; i<n; i++){
        if(pos[level[i]]>index){
            rightLevel.push_back(level[i]);
        }
    }

    int lh = 0, rh = 0;
    if(left>0)
        lh = GetHeight(in, leftLevel, height, s, index-1, left);
    
    if(right>0)
        rh = GetHeight(in, rightLevel, height, index+1, e, right);

    height = max(lh+1, rh+1);

    return height;
}

// Time Complexity: O(N).
// Space Complexity: O(N).
int GetHeightQ(vector<int> in, vector<int> level, int n){
    queue<pair<int, pair<int, int>>> q;
    // stores (height, (start, end)).
    q.push({0, {0, n-1}});

    int height, s, e, j, maxH=0;
    for(int i: level){
        // i is the root of subtree from start to end (in inorder).
        height = q.front().first;
        s = q.front().second.first;
        e = q.front().second.second;
        q.pop();

        j = pos[i];

        // order of pushing matters -- because in level order traversal we first visit left node.
        // push left subtree in queue.
        if(s<j)
            q.push({height+1, {s, j-1}});

        // push right subtree in queue.
        if(e>j)
            q.push({height+1, {j+1, e}});
        
        maxH = max(maxH, height);
    }

    return height;
}

int main(){
    vector<int> in = {7, 4, 2, 1, 5, 3, 6};
    vector<int> level = {1, 2, 3, 4, 5, 6, 7};

    int h = 0, n = in.size();
    for(int i=0; i<n; i++){
        pos[in[i]] = i;
    }

    cout << GetHeightQ(in, level, n);

    return 0;
}