#include <iostream>
#include <vector>
#include "BST.h"
#include <stack>
using namespace std;

// Time Complexity: O(1) -- On average.
// Space Complexity: O(H) -- H is height.
// we can build similar function to access the elements from last.
// with same complexity.
class BSTIterator{
    stack<Node*> st;
    public:
        BSTIterator(Node *root){
            // initialy push nodes till left most node.
            while(root){
                st.push(root);
                root = root->left;
            }
        }

        bool hasNext(){
            return !st.empty();
        }

        int next(){
            if(hasNext()){
                Node *tmp = st.top();
                int ans = tmp->data;
                st.pop();
                // push the right node of root.
                tmp = tmp->right;
                // push all the left side nodes of that right node in stack.
                while(tmp){
                    st.push(tmp);
                    tmp = tmp->left;
                }
                return ans;
            }

            return -1;
        }
};


int main(){
    Node *root = fromVector({4, 2, 3, 1, 5, 6});
    BSTIterator it = BSTIterator(root);

    cout << it.next() << " ";
    cout << it.hasNext() << " ";
    cout << it.next() << " ";
    cout << it.next() << " ";
    cout << it.next() << " ";
    cout << it.next() << " ";
    cout << it.next() << " ";
    cout << it.hasNext();


    return 0;
}