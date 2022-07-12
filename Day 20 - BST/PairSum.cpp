#include <iostream>
#include <vector>
#include <unordered_set>
#include "BST.h"
using namespace std;

unordered_set<int> s;
bool ans = false;
// Time Complexity: O(N)
// Space Complexity: O(N) -- Can be reduced to O(H) by using BST Iterator and to O(1) by using morris inorder traversal.
void isTherePair(Node *root, int sum){
    if(!root or ans){
        return;
    }

    // Inorder Traversal.
    isTherePair(root->left, sum);

    // checking if (sum-current) exists in tree or not.
    if(s.find(sum - root->data)!=s.end()){
        // if yes, then we have our answer.
        ans = true;
        return;
    }

    // else we add current in set and move forward in InOrder Manner.
    s.insert(root->data);

    isTherePair(root->right, sum);

    return;
}

int main(){
    Node *root = fromVector({3, 2, 1, 4, 6, 5});
    ans = false;
    s.clear();
    isTherePair(root, 110);
    cout << ans;
    return 0;
}