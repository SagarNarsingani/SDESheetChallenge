#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
void GetPath(TreeNode *root, vector<int> &path, int x, bool &found){
    // if node is null or x is already found.
    if(root==NULL || found)
        return;
    
    // push current node.
    path.push_back(root->data);

    // if current node is x, return from here after making found true.
    if(root->data==x){
        found = true;
        return;
    }

    // go to left and right from current node to find x.
    GetPath(root->left, path, x, found);
    GetPath(root->right, path, x, found);

    // if x is found, we won't pop the elements from path.
    if(!found) path.pop_back();

    return;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {1,2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());
    vector<int> path;
    int x;
    cin >> x;
    bool found = false;
    GetPath(root, path, x, found);
    for(int i: path){
        cout << i << " ";
    }

    return 0;
}