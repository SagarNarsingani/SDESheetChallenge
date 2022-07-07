#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

int getHeight(TreeNode *root){
    if(root==NULL){
        return 0;
    }

    return max(getHeight(root->left)+1, getHeight(root->right)+1);
}


// Time Complexity: O(N^2) -- For each node we are traversing tree to find height.
// Space Complexity: O(N) -- Callstack.
int getDiameter(TreeNode *root){
    if(root==NULL){
        return 0;
    }

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    int ld = getDiameter(root->left);
    int rd = getDiameter(root->right);
    return max(max(ld, rd), max(rh+lh, 1));
}

// Time Complexity: O(N) -- Calculating height only once.
// Space Complexity: O(N) -- Callstack.
int getDiaOpt(TreeNode *root, int &diameter){
    if(root==NULL){
        return 0;
    }

    int lh = getDiaOpt(root->left, diameter);
    int rh = getDiaOpt(root->right, diameter);

    diameter = max(diameter, lh+rh);

    return max(lh, rh) + 1;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {1, 2, -1, -1, -1};
    int i=0;
    root = BuildTree(root, nodes, i, nodes.size());
    cout << getDiameter(root) << endl;
    int diam = 0;
    getDiaOpt(root, diam);
    cout << diam; 
    return 0;
}