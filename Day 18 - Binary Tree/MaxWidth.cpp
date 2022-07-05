#include <iostream>
#include <queue>
#include "Tree.h"
#include <algorithm>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
int getMaxWidth(TreeNode *root){

    if(root==NULL) return 0;
    
    int width = 1;
    queue<TreeNode*> q;

    q.push(root);
    q.push(NULL);

    // Level Order Traversal.
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        // at the end of each level.
        if(curr==NULL){
            // take maximum width.
            width = max(width, (int)q.size());
            if(!q.empty())
                q.push(NULL);
            continue;
        }

        if(curr->left)
            q.push(curr->left);
        
        if(curr->right)
            q.push(curr->right);
    }

    return width;
}

int main(){

    TreeNode *root;
    vector<int> nodes = {1, 2, 4, -1, 7, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
    int i=0;
    root = BuildTree(root, nodes, i, nodes.size());

    cout << getMaxWidth(root);
    return 0;
}