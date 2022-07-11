#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        Node  *right, *left;
        int data;

        Node(int val): data(val){
            right=left=NULL;
        }

        ~Node(){
            if(left){
                delete left;
            }

            if(right){
                delete right;
            }
        }
};

void insert(Node *&root, int x){
    if(!root){
        root = new Node(x);
        return;
    }

    if(root->data > x){
        insert(root->left, x);
    } else {
        insert(root->right, x);
    }

    return;
}

Node *fromVector(vector<int> nodes){
    Node* root=NULL;
    for(int i: nodes){
        insert(root, i);
    }
    return root;
}

void traverse(Node *root){
    if(!root){
        return;
    }

    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}