#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include "BST.h"
using namespace std;

// Storing Level Order Traversal, we can use any traversal.
// Time Complexity: O(N).
// Space Complexity: O(N).
string serialize(Node *root){
    if(!root) return "";

    queue<Node*> q;
    q.push(root);
    // will store traversal as string.
    string ser = "";
    while(!q.empty()){
        Node *tmp = q.front();
        q.pop();

        // we will also push NULLs into the queue and represent it as "#".
        if(tmp)
            ser = ser + to_string(tmp->data) + " ";
        else
            ser = ser + "# ";
        
        // if temp is not NULL, we push it's children(which can be NULL) to the queue.
        if(tmp){
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }

    return ser;
}

// Time Complexity: O(N).
// Space Complexity: O(N).
Node *deserialize(string data){
    if(data == "") return NULL;
    // make stream of input data.
    stringstream ss(data);
    string node;
    // take first node.
    getline(ss, node, ' ');

    // level order traversal.
    Node *root = new Node(stoi(node));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *tmp = q.front();
        q.pop();

        // take next node, which will be left of current node (i.e., tmp).
        getline(ss, node, ' ');
        if(node=="#"){
            tmp->left = NULL;
        } else {
            Node *left = new Node(stoi(node));
            tmp->left = left;
            q.push(left);
        }

        // take next node, which will be right of current node (i.e., tmp).
        getline(ss, node, ' ');
        if(node=="#"){
            tmp->right = NULL;
        } else {
            Node *right = new Node(stoi(node));
            tmp->right = right;
            q.push(right);
        }

    }
    return root;
}

int main(){
    Node *root = fromVector({4, 3, 1, 5, 6, 2});
    string ser = serialize(root);
    cout << ser << endl;
    Node *t = deserialize(ser);
    traverse(t);
    cout << endl;
    traverse(root);
    return 0;
}