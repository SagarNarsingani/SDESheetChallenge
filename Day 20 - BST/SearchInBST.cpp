#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(LogN).
// Space Complexity: O(LogN) -- CallStack used.
// N is total Number of Nodes.
bool Search(Node *root, int x){
    if(!root)
        return false;
    
    if(root->data==x)
        return true;
    
    if(root->data > x){
        return Search(root->left, x);
    } else {
        return Search(root->right, x);
    }

    return false;
}

int main(){
    Node *root = fromVector({2, 1, 6, 3, 5, 4});
    traverse(root);
    return 0;
}