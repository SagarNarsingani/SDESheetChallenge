#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N) -- Callstack used.
TreeNode *getAncestor(TreeNode *root, int x, int y){
    if(!root || root->data==x || root->data==y){
        return root;
    }

    TreeNode *left = getAncestor(root->left, x, y);
    TreeNode *right = getAncestor(root->right, x, y);
    // if left is null it means there was niether x or y in left, so return right (which can be null, too).
    if(!left){
        return right;
    }
    // if right is null it means there was niether x or y in right, so return left.
    else if (!right){
        return left;
    }
    // if both are not null, then the current node is our LCA. 
    else {
        return root;
    }
}

int getLCA(TreeNode *root, int x, int y){
    TreeNode *ancestor = getAncestor(root, x, y);
    return ancestor->data;
}

int main(){
    TreeNode *root;
    vector<int> nodes={1, 2, 4, -1, 7, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
    int i=0;
    root = BuildTree(root, nodes, i, nodes.size());

    cout << getLCA(root, 5, 2);
    return 0;
}