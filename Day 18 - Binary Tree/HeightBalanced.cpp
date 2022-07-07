#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N) -- CallStack used.
int checkHeights(TreeNode *root){
    if(root==NULL)
        return 0;
    
    // find left-subtree height.
    int lh = checkHeights(root->left);
    // if lh is -1, tree is not balanced.
    if(lh==-1)
        return -1;

    // find right-subtree height.
    int rh = checkHeights(root->right);
    // if rh is -1, tree is not balanced.
    if(rh==-1)
        return -1;

    // if difference is greater than 1 return -1, means tree is not height balanced.
    if(abs(lh-rh)>1)
        return -1;

    return max(rh, lh)+1;
}

bool isBalanced(TreeNode* root){
    // check the height condition for each subtree.
    int heightCheck = checkHeights(root);
    // if height is -1 tree is not balanced.
    if(heightCheck==-1)
        return false;
    
    return true;
}