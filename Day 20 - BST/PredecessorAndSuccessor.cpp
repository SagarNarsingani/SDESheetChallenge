#include <iostream>
#include <vector>
#include <utility>
#include "BST.h"
using namespace std;

// Time Complexity: O(2*H).
// Space Complexity: O(1).
pair<int, int> inorder(Node *root, int key){
    int suc = -1, pre=-1;

    Node *tmp=root;
    while(tmp){
        // if current node is less than or equal to key we will move to right side
        // as on right elements will be greater than current.
        if(tmp->data <= key){
            tmp = tmp->right;
        } else {
            // if current node is greater than key we will move to left side
            // as on left elements will be less than current. Also note that we are updating the successor here.
            suc = tmp->data;
            tmp=tmp->left;
        }
    }

    tmp=root;
    while(tmp){
        // if current node is less than key we will move to right side
        // as on right elements will be greater than current.
        // will only update predecessor if element is less than key.
        if(tmp->data < key){
            pre = tmp->data;
            tmp = tmp->right;
        } else {
            // else will move to left to find lower elements.
            tmp = tmp->left;
        }
    }
    
    return {pre, suc};
}

int main(){
    Node *root = fromVector({12});
    auto p = inorder(root, 12);
    cout << p.first << " " << p.second;
    return 0;
}