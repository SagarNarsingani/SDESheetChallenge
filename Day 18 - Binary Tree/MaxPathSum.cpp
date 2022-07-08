#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

int cnt;

// Time Complexity: O(N).
// Space Complexity: O(N) -- Callstack Used.
int getMaxSumPath(TreeNode *root, long long int &pathSum){
    if(!root) return 0;

    // calculating leaf nodes, if at the end we found that there is only one we will return -1.
    if(!root->left and !root->right) cnt++;

    // max from left side.
    long long int lMax = getMaxSumPath(root->left, pathSum);
    // max from right side.
    long long int rMax = getMaxSumPath(root->right, pathSum);

    // updating path sum if current one is greater than previous.
    pathSum = max(pathSum, lMax+rMax+(root->data));

    // will take max one in consideration.
    return  max(lMax, rMax) + (root->data);
}

int main(){
    TreeNode *root;
    vector<int> nodes={5, 6, 4, 9, -1, -1, 7, -1, -1, 3, -1, -1, 2, -1, -1};
    int i=0;
    root = BuildTree(root, nodes, i, nodes.size());

    long long int ans=0;
    cnt = 0;
    getMaxSumPath(root, ans);

    // if there is only one leaf node.
    if (cnt==1) ans = -1;
    cout << ans << endl;
    return 0;
}