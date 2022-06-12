#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

        ListNode(int d): data(d), next(NULL){};

        ~ListNode(){
            while(next){
                delete next;
            }
        }
};

// Time Complexity: O(1).
void DeleteNode (ListNode *node){
    node->data = node->next->data;
    node->next = node->next->next;
    return;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode* temp = head;

    // creating list
    vector<int> arr = {2, 3, 4, 5};
    for(int i: arr){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }

    DeleteNode(head->next->next);

    temp=head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    delete head;
    return 0;
}