#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N).
bool isBST(Node *root){
    if(!root)
        return true;

    // checking current node.
    int val = root->data;
    if(root->right and (root->right->data < val)){
        return false;
    }

    if(root->left and (root->left->data > val)){
        return false;
    }

    // checking childs.
    return isBST(root->left) && isBST(root->right);
}

int main(){
    Node *root = fromVector({1, 2, 3, 4, 5, 6});
    cout << isBST(root);
    return 0;
}