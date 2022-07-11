#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
// N -- Total Number of Nodes.
Node *ArrayToBinary(int s, int e, vector<int> arr){
    if(s>e)
        return NULL;
    int mid = s+(e-s)/2;
    Node *node = new Node(arr[mid]);

    node->left = ArrayToBinary(s, mid-1, arr);
    node->right = ArrayToBinary(mid+1, e, arr);

    return node;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *root = ArrayToBinary(0, arr.size()-1, arr);
    traverse(root);
    return 0;
}