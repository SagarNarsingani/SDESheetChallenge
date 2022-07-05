#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
// N - total number of nodes.
vector<int> GetVerticalOrder(TreeNode *root){
    if(root==NULL)
        return {};
    
    // will store vertical lines and nodes belong to corresponding line.
    map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    // level order traversing.
    while(!q.empty()){
        TreeNode* curr = q.front().first;
        int line = q.front().second;

        q.pop();

        // adding current node(curr->data) to its corresponding vertical(line).
        m[line].push_back(curr->data);

        // only nodes that are not NULL are pushed into queue.
        // Left child will be one line back.
        // right child will be one line ahead.
        if(curr->left)
            q.push({curr->left, line-1});
        
        if(curr->right)
            q.push({curr->right, line+1});
    }

    // collecting all nodes in one list.
    vector<int> verticalOrder;
    for(auto p: m){
        for(int i: p.second){
            verticalOrder.push_back(i);
        }
    }

    return verticalOrder;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {2, 7, 2, -1, -1, 6, 5, -1, -1, 11, -1, -1, 5, -1, 9, 4, -1, -1, -1};
    int i=0;

    root = BuildTree(root, nodes, i, nodes.size());

    vector<int> vertical = GetVerticalOrder(root);

    for(int i: vertical){
        cout << i << " ";
    }

    return 0;
}