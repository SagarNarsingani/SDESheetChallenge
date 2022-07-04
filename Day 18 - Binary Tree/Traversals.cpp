#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left, *right;

        TreeNode(int d): data(d){
            left = right = NULL;
        };
};

// Just for traversals.
// Time Complexity: O(N) -- N is number of nodes.
// Space Complexity: O(H) -- H is maximum height of a tree.
class Tree{

    public:
        TreeNode *root;

        TreeNode* BuildTree(TreeNode* root, int &i,vector<int> nodes){
            if(nodes[i]==-1 || i>=nodes.size()){
                i++;
                return NULL;
            }
            
            root = new TreeNode(nodes[i]);
            i++;

            root->left = BuildTree(root->left, i, nodes);
            root->right = BuildTree(root->right, i, nodes);

            return root;
        }

        void PreOrderTraversal(TreeNode* root){
            if(root==NULL){
                return;
            }

            cout << root->data << " ";
            PreOrderTraversal(root->left);
            PreOrderTraversal(root->right);

            return;
        }

        void PostOrderTraversal(TreeNode *root){
            if(root==NULL){
                return;
            }

            PostOrderTraversal(root->left);
            PostOrderTraversal(root->right);
            cout << root->data << " ";

            return;
        }

        void InOrderTraversal(TreeNode *root){
            if(root==NULL){
                return;
            }

            InOrderTraversal(root->left);
            cout << root->data << " ";
            InOrderTraversal(root->right);

            return;
        }

};

int main(){
    Tree t;
    int i=0;

    t.root = t.BuildTree(t.root, i, {1, 3, 5, -1, -1, 2, -1, -1, 4, 7, -1, -1, 6, -1, -1});

    t.InOrderTraversal(t.root);
    return 0;
}