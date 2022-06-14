#include <iostream>
#include <vector>
using namespace std;

// Class for Linked List
class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode *random;

        ListNode(int d): data(d), next(NULL), random(NULL){};

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

ListNode *addRandoms(ListNode *head, vector<int>randoms){
    ListNode *curr=head;
    int i=0;
    while(curr){
        if(randoms[i]==-1){
            curr->random = NULL;
            i++;
            break;
        }
        ListNode *temp=head;
        while(temp){
            if(temp->data == randoms[i]){
                curr->random = temp;
            }
            temp = temp->next;
        }
        curr = curr->next;
        i++;
    }

    return head;
}

// In another approach we can use hash table to store address of corresponding deep copy of each node with itself.
// It will cost O(N) time and O(N) space. 

// Time Complexity: O(N).
// Space Complexity: O(1).
ListNode *CreateDeepCopy(ListNode *head){
    if(head==NULL) return head;
    if(head->next==NULL){
        ListNode *copy = new ListNode(head->data);
        if(head->random==NULL){
            copy->random = NULL;
        } else {
            copy->random = copy;
        }
        return copy;
    }
    // Creating Copies.
    ListNode *tmp=head;
    while(tmp){
        ListNode *cpy = new ListNode(tmp->data);
        ListNode *nxt = tmp->next;
        tmp->next = cpy;
        cpy->next = nxt;
        tmp = nxt;
    }

    // Assigning randoms to the copies.
    tmp=head;
    while(tmp){
        ListNode *random = tmp->random;

        if(random==NULL)
            tmp->next->random = NULL;
        else 
            tmp->next->random = random->next;

        tmp = tmp->next->next;
    }

    // detaching both the linked lists.
    tmp = head;
    ListNode *copy = head->next;
    while(tmp){
        ListNode *cpy = tmp->next;
        tmp->next = cpy->next;
        if(cpy->next)
            cpy->next = cpy->next->next;
        tmp = tmp->next;
    }

    return copy;
}

int main(){
    ListNode *head = CreateList({1, 2, 3, 4, 5});
    vector<int> randoms = {3, 1, 5, 5, 2};
    head = addRandoms(head, randoms);

    ListNode *copy = CreateDeepCopy(head);

    ListNode *tmp = copy;
    while(tmp){
        cout << tmp->random->data << " ";
        tmp = tmp->next;
    }
    // head = 

    return 0;
}