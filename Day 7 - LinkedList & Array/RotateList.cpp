#include <iostream>
#include <vector>
using namespace std;

// Class for Linked List
class ListNode{
    public:
        int data;
        ListNode *next;

        ListNode(int d): data(d), next(NULL){};

        ~ListNode(){
            while(next){
                delete next;
            }
        }
};

// function to create Linked List from a vector.
ListNode *CreateList(vector<int> arr){
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for(int i: arr){
        ListNode *temp = new ListNode(i);
        curr->next = temp;
        curr = curr->next;
    }

    return head->next;
}

// Time Complexity: O(N).
// Space Complexity: O(1).
ListNode *RotateList(ListNode *head, int k){

    // Corner Cases.
    if(head==NULL or head->next==NULL or k==0) return head;

    // Calculating Length.
    int len = 0;
    ListNode *tmp = head;
    while(tmp){
        len++;
        tmp = tmp->next;
    }

    // Calculate number of nodes to be actually rotated.
    k = k%len;
    if(k==0) return head;
    int i = len-k;

    // find point from which elements will be shifted to start.
    tmp = head;
    while(i>1){
        tmp=tmp->next;
        i--;
    }
    
    // shift elements to the start.
    ListNode *rotated = tmp->next, *temp = tmp->next;
    tmp->next = NULL;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = head;

    return rotated;
}

int main(){
    ListNode *head = CreateList({2, 4});
    head = RotateList(head, 3);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}