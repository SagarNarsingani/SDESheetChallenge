#include <iostream>
#include <vector>
#include <utility>
#include "Tree.h"
using namespace std;

int getVal(TreeNode *node){
    if(!node)
        return 0;
    return node->data;
}

pair<int, int> getSumPair(int sum){
    int half = sum/2;
    if(sum&1){
        return {half, half+1};
    }
    return {half, half};
}

// Time Complexity: O(N).
// Space Complexity: O(N) -- Callstack.
void makeTreeSummed(TreeNode *root){
    int cur = getVal(root);

    if(cur==0) return;

    int l = getVal(root->left);
    int r = getVal(root->right);

    int sum = l+r;

    // for leaf node.
    if(sum==0) return;

    // compare sum of child and value of current node.
    if(sum>cur){
        root->data = sum;
    } else if(sum<cur){
        // if anyone child is NULL, other child will take value of parent.
        if(l==0){
            root->right->data = cur;
        } else if(r==0){
            root->left->data = cur;
        } else {
            // if both child are present, both will take half value of parent.
            auto sp = getSumPair(cur-sum);
            root->right->data = root->right->data + sp.first;
            root->left->data = root->left->data + sp.second;
        }
    }

    // going to check children.
    makeTreeSummed(root->left);
    makeTreeSummed(root->right);

    // Instead of Check tree.
    l = getVal(root->left);
    r = getVal(root->right);

    sum = l+r;

    // if not leaf node.
    // if sum of children has changed we will update value of current node.
    if(sum)
        root->data = sum;

    return;
}

// To check if tree is in Summed manner.
bool checkTree(TreeNode *root){
    if(!root)
        return true;
    
    int cur = getVal(root);
    int l = getVal(root->left);
    int r = getVal(root->right);

    if(l+r==0) return true;

    return (cur==l+r) and checkTree(root->left) and checkTree(root->right);
}

int main(){
    TreeNode *root;
    int i=0;
    vector<int> nodes = {118, 91, 165, -1, 83, -1, -1, -1, -1};
    root = BuildTree(root, nodes, i, nodes.size());

    // while(!checkTree(root)){
    //     makeTreeSummed(root);
    //     InOrder(root);
    // }

    makeTreeSummed(root);
    InOrder(root);

    return 0;
}