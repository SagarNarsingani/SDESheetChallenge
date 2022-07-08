#include <iostream>
#include <vector>
#include <unordered_map>
#include "Tree.h"
using namespace std;

TreeNode *ConstructTree(vector<int> &in, int inStart, int inEnd, vector<int> &post, int postStart, int postEnd, unordered_map<int, int> &indices){
    if(inStart > inEnd || postStart < postEnd)
        return NULL;
    
    TreeNode *root = new TreeNode(post[postStart]);
    // post order traversal in range (i...end) will show post order traversal of right subtree.
    // (start...i-1) will show post order traversal of left subtree.
    int i = indices[root->data];
    int j = i-inStart;

    root->left = ConstructTree(in, inStart, i-1, post, postEnd+j-1, postEnd, indices);
    root->right = ConstructTree(in, i+1, inEnd, post, postStart-1, postEnd+j, indices);

    return root;
}

// Time Complexity: O(N).
// Space Complexity: O(N).
TreeNode *BuildTreeFromTraversals(vector<int> in, vector<int> post){
    int inStart = 0, inEnd = in.size()-1;
    // the last element each time will show the root for current range.
    int postStart = post.size()-1, postEnd = 0;

    unordered_map<int, int> indices;
    for(int i=0; i<=inEnd; i++){
        indices[in[i]] = i;
    }

    return ConstructTree(in, inStart, inEnd, post, postStart, postEnd, indices);
}