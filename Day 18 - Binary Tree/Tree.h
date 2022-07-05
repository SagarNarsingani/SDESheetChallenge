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