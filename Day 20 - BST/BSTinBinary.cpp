#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

class NodeData{
    public:
        int maxnode;
        int minnode;
        int size;

        NodeData(int maxnode, int minnode, int size){
            this->maxnode = maxnode;
            this->minnode = minnode;
            this->size = size;
        }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
NodeData BSTinBinary(Node *root){
    if(!root){
        // parent of this node will always fall in the range.
        return NodeData(INT_MIN, INT_MAX, 0);
    }

    // PostOrder Traversal.
    NodeData left = BSTinBinary(root->left);
    NodeData right = BSTinBinary(root->right);

    // will increase the size if current node falls into appropriate range.
    int val = root->data;
    if(val>=left.maxnode && val<=right.minnode){
        return NodeData(max(val, right.maxnode), min(val, left.minnode), left.size+right.size+1);
    }

    // if node doesn't fall in range, then we return this.
    // parent of this never falls in the range.
    return NodeData(INT_MAX, INT_MIN, max(right.size, left.size));
}

int main(){
    Node *root = fromVector({5, 4, 6, 7, 1, 2, 3});
    NodeData size= BSTinBinary(root);
    cout << size.size << endl;
    return 0;
}