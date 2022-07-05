#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left, *right;

        TreeNode(int d){
            data = d;
            right = left = NULL;
        }

        ~TreeNode(){
            if(left)
                delete left;
            
            if(right)
                delete right;
        }
};

TreeNode *BuildTree(TreeNode *root, vector<int> nodes, int &i, int n){
    if(i>=n || nodes[i]==-1){
        i++;
        return NULL;
    }

    root = new TreeNode(nodes[i]);
    i++;

    root->left = BuildTree(root->left, nodes, i, n);
    root->right = BuildTree(root->right, nodes, i, n);

    return root;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> GetLevelOrder(TreeNode *root){
    if(root==NULL) return {};
    queue<TreeNode*> q;
    q.push(root);

    vector<int> levelOrder;

    // Level Order Traversal.
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        levelOrder.push_back(curr->data);

        if(curr->left)
            q.push(curr->left);
        
        if(curr->right)
            q.push(curr->right);

    }

    return levelOrder;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {1, 2, 4, -1, 7, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
    int i=0;

    root = BuildTree(root, nodes, i, nodes.size());

    vector<int> level = GetLevelOrder(root);

    for(int i: level){
        cout << i << " ";
    }

    return 0;
}