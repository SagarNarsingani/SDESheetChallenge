#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// This will traverse in reverse sorted order.
// Time Complexity: O(N)
// Space Complexity: O(N) -- Can be reduced using morris traversal.
void revInOrder(Node *root, int &k, int &ans){
    if(!root || ans!=-1)
        return;
    
    // first go to right.
    revInOrder(root->right, k, ans);

    // access root node here.
    k--;
    if(k==0){
        ans = root->data;
        return;
    }

    // then to left.
    revInOrder(root->left, k, ans);

    return;
}

int main(){
    Node *root = fromVector({3, 1, 5, 2, 6});
    int ans = -1, k = 3;
    revInOrder(root, k, ans);
    // cout << endl;
    cout << ans;
    return 0;
}