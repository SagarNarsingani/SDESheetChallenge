#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N).
bool isBST(Node *root, int s, int e){
    if(!root)
        return true;

    // checking current node.
    int val = root->data;
    // each node should appear in particular range only.
    if(val<=s || val>=e)
        return false;

    // checking childs.
    return isBST(root->left, s, val) && isBST(root->right, val, e);
}

int main(){
    Node *root = fromVector({1, 2, 3, 4, 5, 6});
    cout << isBST(root, INT_MIN, INT_MAX);
    return 0;
}