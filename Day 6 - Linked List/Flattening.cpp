// To be optimized...

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Class for Linked List
class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode *child;

        ListNode(int d): data(d), next(NULL), child(NULL){};

        ~ListNode(){
            while(next){
                delete next;
            }
        }
};

// function to create Linked List from a vector.
ListNode *CreateList(vector<int> arr){
    if(arr.size()==0) return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for(int i: arr){
        ListNode *temp = new ListNode(i);
        curr->next = temp;
        curr = curr->next;
    }

    return head->next;
}

// Function to create Child Lists.
ListNode *CreateBottomList(vector<int> arr){
    if(arr.size()==0) return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for(int i: arr){
        ListNode *temp = new ListNode(i);
        curr->child = temp;
        curr = curr->child;
    }

    return head->child;
}

// Function to merge two child lists in one in sorted manner.
ListNode *Merge(ListNode *head1, ListNode *head2){
    ListNode *res = NULL;

    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1->data <= head2->data){
        res = head1;
        res->child = Merge(head1->child, head2);
    } else {
        res = head2;
        res->child = Merge(head1, head2->child);
    }

    return res;
}


// Space Complexity: O(N).
// Time Complexity: O(N*N*M).
ListNode *Flatten(ListNode *head){
    if(head==NULL or head->next==NULL) return head;

    head->next = Flatten(head->next);

    head = Merge(head, head->next);

    // To see step-wise build up of whole flat list.
    // ListNode *curr = head;
    // while(curr){
    //     cout << curr->data << " ";
    //     curr = curr->child;
    // }
    // cout << endl;

    return head;
}

ListNode *mergesort(ListNode *head){
    ListNode *tmp1 = head;
    while(tmp1){
        ListNode *tmp2 = tmp1;
        while(tmp2->child){
            tmp2 = tmp2->child;
        }
        tmp2->child = tmp1->next;
        tmp1 = tmp1->next;
    }

    

    return head;
}

int main(){
    // Creating List.
    ListNode *head = CreateList({3, 5, 22, 26, 39});

    // adding child lists for each node of main list.
    vector<vector<int>> childs = {
        {4,6},
        {11, 14},
        {25},
        {28},
        {}
    };
    ListNode *curr = head;
    for(auto i: childs){
        ListNode *temp = CreateBottomList(i);
        curr->child = temp;
        curr = curr->next;
    }

    // Printing Initial List.
    // curr = head;
    // while(curr){
    //     ListNode *tmp = curr;
    //     while(tmp){
    //         cout << tmp->data << " ";
    //         tmp = tmp->child;
    //     }
    //     cout << endl;
    //     curr = curr->next;
    // }

    // Printing Flat List.
    curr = mergesort(head);
    while(curr){
        cout << curr->data << " ";
        curr = curr->child;
    }

    return 0;
}