#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(H).
// Space Complexity: O(1).
int getFloor(Node *root, int x){
    int ans;

    while(root){
        // if data is less than x we will move to right, where data will increase.
        if(root->data <= x){
            ans = root->data;
            if(ans==x) break;   // as per que, if x itself exists in tree we need to return it hence
            root = root->right; // there is no meaning of going further.
        } else {
            // else go to left, where data decreases.
            root = root->left;
        }
    }

    return ans;
}

int main(){
    Node *root = fromVector({10, 5, 15, 2, 6});
    cout << getFloor(root, 5);
    return 0;
}