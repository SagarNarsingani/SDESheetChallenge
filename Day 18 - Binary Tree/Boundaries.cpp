#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;


bool isLeaf(TreeNode *node){
    return (!node->left && !node->right);
}

// Get Left Boundary.
void getLeftBoundary(TreeNode *root, vector<int> &boundary){
    TreeNode *curr = root->left;
    while(curr){
        if(!isLeaf(curr))
            boundary.push_back(curr->data);
        else break;

        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right; 
    }
    return;
}

// Get all leaves from tree.
void getLeaves(TreeNode *root, vector<int> &boundary){
    if(isLeaf(root)){
        boundary.push_back(root->data);
        return;
    }

    if(root->left) getLeaves(root->left, boundary);
    if(root->right) getLeaves(root->right, boundary);

    return;
}

// Get Right boundary in reverse order.
void getRightBoundary(TreeNode *root, vector<int> &boundary){
    vector<int> temp;
    TreeNode *curr = root->right;
    while(curr){
        if(!isLeaf(curr))
            temp.push_back(curr->data);
        else break;

        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i=temp.size()-1; i>=0; i--){
        boundary.push_back(temp[i]);
    }

    return;
}

// Time Complexity: O(N).
// Space Complexity: O(N) -- Callstack used while finding leaves.
vector<int> getBoundaryTraversal(TreeNode *root){
    vector<int> boundary;
    
    if(!root)
        return boundary;

    if(!isLeaf(root)) boundary.push_back(root->data);

    getLeftBoundary(root, boundary);
    getLeaves(root, boundary);
    getRightBoundary(root, boundary);

    return boundary;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {10, 5, 3, -1, -1, 8, 7, -1, -1, -1, 20, 18, -1, -1, 25, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());

    vector<int> b = getBoundaryTraversal(root);

    for(int i: b){
        cout << i << " ";
    }

    return 0;
}