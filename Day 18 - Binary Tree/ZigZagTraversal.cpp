#include <iostream>
#include <vector>
#include <queue>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N) -- vectors and queue.
vector<int> GetZigZagTraversal(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    vector<int> zigzag;
    bool rev = false;
    
    // Level Order Traversal. 
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size, 0);
        // all the nodes of current level at once...
        for(int i=0; i<size; i++){
            TreeNode *tmp = q.front();
            q.pop();
            // based on rev, finding the index.
            int idx = !rev ? i : (size-i-1);
            row[idx] = tmp->data;

            if(tmp->left){
                q.push(tmp->left);
            }

            if(tmp->right){
                q.push(tmp->right);
            }
        }

        // pushing current results in final vector.
        for(int i: row){
            zigzag.push_back(i);
        }

        rev = !rev;
    }
    return zigzag;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {1, 3, 5, -1, -1, 2, -1, -1, 4, 7, -1, -1, 6, -1, -1};
    int i=0;
    root = BuildTree(root, nodes, i, nodes.size());
    vector<int>z = GetZigZagTraversal(root);
    for(int i: z){
        cout << i << " ";
    }

    return 0;
}
