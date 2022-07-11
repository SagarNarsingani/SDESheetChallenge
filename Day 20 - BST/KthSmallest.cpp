#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Inorder will give elements in sorted manner.
// will take kth one and return from there.
// Time Complexity: O(N)
// Space Complexity: O(N) -- Can be reduced using Moris traversal.
void InOrder(Node *root, int &k, int &ans){
    if(!root || ans!=-1){
        return;
    }

    // go to left.
    InOrder(root->left, k, ans);
    
    // access the root here.
    k--;
    if(k==0){
        ans = root->data;
        return;
    }

    // then go to right.
    InOrder(root->right, k, ans);

    return;
}

int main(){

    Node *root = fromVector({3, 1, 2, 6, 5, 4});
    int ans = -1;
    int k = 4;
    InOrder(root, k, ans);
    cout << ans;
    return 0;
}