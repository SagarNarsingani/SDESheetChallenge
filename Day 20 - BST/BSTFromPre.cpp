#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

Node *BSTFromPre(vector<int> &arr, int &i, int upper){
    // if node crosses the upper bound.
    if(i==arr.size() || arr[i]>upper){
        return NULL;
    }

    Node *node = new Node(arr[i++]);
    // on the left side value of current node is the upper bound.
    node->left = BSTFromPre(arr, i, node->data);
    // on the right side the upper bound for current node is the upper bound.
    node->right = BSTFromPre(arr, i, upper);

    return node;
}

// Time Complexity: O(N*N).
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
    int i = 0;
    Node *root=BSTFromPre(pre, i, INT_MAX);
    // for(int i: pre){
    //     addNode(root, i);
    // }
    traverse(root);
    return 0;
}