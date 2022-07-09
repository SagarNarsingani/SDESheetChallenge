#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N) -- CallStack.
bool isSymmetric(TreeNode *node1, TreeNode* node2){
    if(!node1 ^ !node2) return false;

    if(!node1 and !node2)   return true;

    if(node1->data == node2->data)
        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
    else return false;
}

bool checkSymmetry(TreeNode *root){
    if(!root)
        return true;
    
    return isSymmetric(root->left, root->right);
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nodes = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};
    root = BuildTree(root, nodes, i, nodes.size());

    cout << checkSymmetry(root);
}