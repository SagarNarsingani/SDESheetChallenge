#include <iostream>
#include <vector>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

        ListNode(int d){
            data = d;
            next = NULL;
        }

        ~ListNode(){
            while(next){
                delete next;
            }
        }
};

// Time Complexity: O(N).
// Space Complexity: O(N).
ListNode* ReverseList(ListNode* head){
    ListNode *curr = head, *prev=NULL;

    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    return head;
}

int main(){
    ListNode head(1);
    ListNode* temp = &(head);

    // creating list
    vector<int> arr = {2, 3, 4, 5};
    for(int i: arr){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }

    // printing reversed list
    temp = ReverseList(&head);
    while(temp){
        cout << temp->data << " ";
        temp=temp->next;
    }
    return 0;
}