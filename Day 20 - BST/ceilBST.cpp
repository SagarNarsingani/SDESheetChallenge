#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(H)
// Space Complexity: O(1)
int getCeil(Node *root, int x){
    int ceil=-1;
    while(root){
        // if data is less than key, will move to right.
        // where data will increase.
        if(root->data < x){
            root = root->right;
        } else {
            // if data is greater than key, we will set data as ceil
            // and move to left where data will decrease.
            ceil = root->data;
            if(ceil==x) break;
            root = root->left;
        }
    }

    return ceil;
}

int main(){
    Node *root = fromVector({8, 3, 10, 1, 6, 14, 4, 7, 13});
    cout << getCeil(root, 12);
    return 0;
}