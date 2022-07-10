#include <iostream>
#include <vector>
#include "Tree.h"
#include <queue>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
void ConnectNodesAtSameLevel(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            TreeNode *tmp = q.front();
            q.pop();
            // we shouldn't connect last node of level with any other node.
            if(i<n-1)
                tmp->next = q.front();
            // last node's next should be NULL.
            else
                tmp->next = NULL;

            // pushing childs of current level (i.e., next level).
            if(tmp->left)
                q.push(tmp->left);
            
            if(tmp->right)
                q.push(tmp->right);
        }
    }

    return;
}