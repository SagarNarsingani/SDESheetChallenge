#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N) -- Callstack used.
bool checkNodes(TreeNode* r1, TreeNode* r2){
    if(!r1 and !r2){
        return true;
    }

    if((!r1 and r2) || (r1 and !r2) || r1->data!=r2->data){
        return false;
    }

    return (checkNodes(r1->left, r2->left) && checkNodes(r1->right, r2->right));
}

