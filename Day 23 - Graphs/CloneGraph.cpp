#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Graph.h"
using namespace std;


unordered_map<int, graphNode*> mp;
// Time Complexity: O(V+E).
// Space Complexity: O(V).
graphNode *cloneNode(graphNode *root){
    
    queue<graphNode*>q;
    q.push(root);

    graphNode *newRoot = new graphNode(root->data);
    mp[root->data] = newRoot;

    // Breadth First Search
    // while loop will run V times -- V is number of vertices.
    while(!q.empty()){
        graphNode *tmp = q.front();
        q.pop(); 

        graphNode *node = mp[tmp->data];

        // will run for E times -- E is Number of Edges.
        for(auto i: tmp->nbrs){
            if(mp.find(i->data)==mp.end()){
                mp[i->data] = new graphNode(i->data);
                // only push those in queue, which are yet to visited.
                q.push(i);
            }

            graphNode *nbr = mp[i->data];
            
            // push all neighbours in current node.
            node->nbrs.push_back(nbr);
        }
    }

    return newRoot;
}

int main(){
    graphNode *root = new graphNode(1);
    graphNode *node1 = new graphNode(2);
    graphNode *node2 = new graphNode(3);
    // graphNode *node3 = new graphNode(4);
    // graphNode *node4 = new graphNode(5);


    root->nbrs.push_back(node1);
    node1->nbrs.push_back(root);

    root->nbrs.push_back(node2);
    node2->nbrs.push_back(root);


    traverse(root);

    cout << endl;
    graphNode *clone = cloneNode(root);

    traverse(clone);

    return 0;
}