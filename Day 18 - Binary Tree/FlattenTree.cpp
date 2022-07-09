#include <iostream>
#include <vector>
#include <stack>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N) -- Callstack.
TreeNode *pre = NULL;
void flattenRec(TreeNode *root){
    if(!root)
        return;
    
    // first go to right side.
    flattenRec(root->right);
    // then to left.
    flattenRec(root->left);

    root->right = pre;
    root->left = NULL;
    pre = root;

    return;
}

// Time Complexity: O(N).
// Space Complexity: O(N).
void flattenStack(TreeNode *root){
    if(!root)
        return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *curr = st.top();
        st.pop();
        // right subtree stored.
        if(curr->right){
            st.push(curr->right);
        }

        // left subtree stored.
        if(curr->left){
            st.push(curr->left);
        }

        // right subtree deleted (if left exists).
        if(!st.empty())
            curr->right = st.top();
        
        curr->left=NULL;
    }

    return;
}

// Time Complexity: O(N).
// Space Complexity: O(1).
void MorrisTravesal(TreeNode *root){
    if(!root)
        return;
    
    TreeNode *cur = root;
    while(cur){
        if(cur->left){
            TreeNode *pre = cur->left;
            // find right most node in left subtree.
            while(pre->right){
                pre = pre->right;
            }

            // point to right of current from that right most node.
            pre->right = cur->right;
            // move left subtree of curr to its right.
            cur->right = cur->left;
            // make left of curr NULL.
            cur->left = NULL;
        }
        // move to next (which will be at right, as left is NULL).
        cur = cur->right;
    }
    
    return;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {15, 40, -1, -1, 62, 10, -1, -1, 20, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());

    pre=NULL;
    flattenRec(root);

    while(root){
        cout << root->data << " ";
        root = root->right;
    }
    return 0;
}