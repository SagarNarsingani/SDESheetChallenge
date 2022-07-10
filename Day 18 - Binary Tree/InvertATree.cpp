#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N) -- Callstack.
TreeNode *node = NULL;
TreeNode *Invert(TreeNode *root, int x){
    // if required leaf node is found.
    if(root->data==x){
        node = root;    // storing in node to access it in the end.
        return root;
    }
    
    // will go only if path exists.
    if(root->left){
        // Check and Invert (if required) the left part.
        TreeNode *left = Invert(root->left, x);
        // if left part is already inverted.
        if(left){
            // parent to left of child.
            left->left = root;
            // parent's left becomes NULL.
            root->left = NULL;
            // return current parent node from here.
            return root;
        }
    }    
    if(root->right){
        // Check and Invert (if required) the right part.
        TreeNode *right = Invert(root->right, x);
        // if right is already inverted.
        if(right){
            // parent goes to left of child.
            right->left = root;
            // right of parent goes to left of parent.
            root->right = root->left;
            // left of parent becomes NULL.
            root->left = NULL;
            // return current parent node from here.
            return root;
        }
    }

    return NULL;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {5, 6, 4, -1, -1, 1, -1, -1, 15, -5, -1, -1, 2, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());
    Invert(root, 1);
    if(node){
        InOrder(node);
    }
    return 0;
}