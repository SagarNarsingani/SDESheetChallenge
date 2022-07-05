#include <iostream>
#include <vector>
#include <queue>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> GetLeftView(TreeNode *root){
    if(root==NULL) return {};
    queue<TreeNode*> q;
    vector<int> leftView;
    q.push(root);
    q.push(NULL);
    leftView.push_back(root->data);
    // Using Inorder Traversal.
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        
        // whenever current level finishes we push the first element of next level in answer.
        if(tmp==NULL && !q.empty()){
            leftView.push_back(q.front()->data);
            q.push(NULL);
            continue;
        }
        
        // if we are at the end of all nodes.
        if(tmp==NULL) break;

        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }

    return leftView;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {5, 7, 14, -1, -1, 19, -1, -1, 10, 30, -1, -1, 15, 25, -1, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());
    vector<int> Left = GetLeftView(root);

    for(int i: Left){
        cout << i << " ";
    }
    return 0;
}