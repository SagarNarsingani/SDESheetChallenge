#include <iostream>
#include <vector>
#include "Tree.h"
#include <unordered_map>

unordered_map<int, int> index;
TreeNode *ConstructTree(vector<int> in, int inStart, int inEnd, vector<int> pre, int preStart, int preEnd){
    if(inStart>inEnd || preStart>preEnd)
        return NULL;
    
    // in pre, till elem we will have preorder traversal of left subtree, after than of right subtree.
    int elem = index[pre[preStart]];
    int elemEnd = elem - inStart;

    TreeNode *root = new TreeNode(pre[preStart]);

    // each time we are discarding 1st preorder element.
    root->left = ConstructTree(in, inStart, elem-1, pre, preStart+1, preStart+elemEnd);
    root->right = ConstructTree(in, elem+1, inEnd, pre, preStart+elemEnd+1, preEnd);

    return root;
}

// Time Complexity: O(N).
// Space Complexity: O(N).
TreeNode *BuildTreeFromTraversals(vector<int> pre, vector<int> in){
    int inStart = 0, preStart = 0;
    int inEnd = in.size()-1, preEnd = pre.size()-1;

    for(int i=0; i<inEnd; i++){
        index[in[i]] = i;
    }

    return ConstructTree(in, inStart, inEnd, pre, preStart, preEnd);
}