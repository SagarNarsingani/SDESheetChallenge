#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> GetTopView(TreeNode *root){

    if(root==NULL)
        return {};

    // will store line number and corresponding first element of that line.
    map<int, int> m;
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});
    // Level Order Traversal.
    while(!q.empty()){
        TreeNode *curr = q.front().first;
        int line = q.front().second;

        q.pop();

        // only store first element of each line.
        if(m.find(line)==m.end()){
            m[line] = curr->data;
        }

        if(curr->left)
            q.push({curr->left, line-1});
        
        if(curr->right)
            q.push({curr->right, line+1});
    }

    vector<int> topView;
    for(auto p: m){
        topView.push_back(p.second);
    }

    return topView;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {1, 2, 4, -1, 7, 9, 10, -1, -1, -1, -1, 5, -1, -1, 3, -1, 6, 8, -1, 11, -1, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());

    vector<int> Top = GetTopView(root);

    for(int i: Top){
        cout << i << " ";
    }
    return 0;
}