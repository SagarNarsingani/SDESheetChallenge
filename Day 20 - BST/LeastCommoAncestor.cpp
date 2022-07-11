#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

Node *getLCA(Node *root, Node *x, Node *y){
    if(!root){
        return NULL;
    }

    // fixing lower and upper bounds.
    int xv = min(x->data, y->data);
    int yv = max(x->data, y->data);

    int cur = root->data;

    // if current node is in the range than it is the LCA, we are looking for.
    if(cur>=xv and cur<=yv){
        return root;
    }

    // if current node is less than lower bound we must increase current node
    // and to do so we need to go right.
    if(cur<xv){
        return getLCA(root->right, x, y);
    }

    // if current node is greater than upper bound we must decrease current node
    // and to do so we need to go left.
    if(cur>yv){
        return getLCA(root->left, x, y);
    }

    return NULL;
}


int main(){
    Node *root = fromVector({2, 1, 4, 3});
    Node *lca = getLCA(root, new Node(3), new Node(4));
    if(lca)
        cout << lca->data;
    else 
        cout << "NULL";
    return 0;
}