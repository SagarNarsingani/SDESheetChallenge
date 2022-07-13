#include <iostream>
#include <vector>
#include <utility>
#include "Tree.h"
using namespace std;

Node *strt = NULL;
// will return range of nodes from both sides.
// Time Complexity: O(N).
// Space Complexity: O(N) -- CallStack.
pair<Node*, Node*> Flatten(Node *root){
    // if node is NULL, range will be NULL too.
    if(!root) return {NULL, NULL};
    // left's last's next will be connected to root.
    auto t1 = Flatten(root->left);
    Node *prev = t1.second;
    if(prev){
        prev->right = root;
    }
    root->left = prev;

    if(!strt){
        strt = root;
    }

    // right's first's prev will be connected to root.
    auto t2 = Flatten(root->right);
    Node *next = t2.first;
    if(next){
        next->left = root;
    }
    root->right = next;

    
    return {t1.first ? t1.first : root, t2.second ? t2.second : root};
}

void traverseDLL(Node *root){
    while(root){
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
    return;
}

int main(){
    Tree t = Tree({89, 22, 96, 11, 23, 94, 97, 10, 16, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1});

    t.traverse();

    Flatten(t.root);

    traverseDLL(strt);

    return 0;
}