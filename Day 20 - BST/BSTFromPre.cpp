#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
void addNode(Node *&root, int x){
    if(!root){
        root = new Node(x);
        return;
    }
    
    if(x > root->data){
        addNode(root->right, x);
    } else {
        addNode(root->left, x);
    }

    return;
}

int main(){
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    Node *root=NULL;
    for(int i: pre){
        addNode(root, i);
    }
    traverse(root);
    return 0;
}