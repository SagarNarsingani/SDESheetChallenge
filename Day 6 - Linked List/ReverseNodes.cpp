#include <iostream>
#include <vector>
#include <unordered_set>
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

ListNode *ReverseNodes(ListNode *head, int l){
    if(head==NULL or head->next==NULL or l==0) return head;

    int i=0;
    ListNode *curr=head, *prev=NULL;
    while(i<l){
        ListNode *tmp = curr;
        curr = curr->next;
        tmp->next = prev;
        prev = tmp;
        i++;
    }

    return prev;
}

ListNode *ReverseList( ListNode *head, int b[], int n ){
    ListNode *curr = head;
    int len=0;
    while(curr){
        len++;
        curr = curr->next;
    }

    curr= new ListNode(-1);
    curr->next = head;
    int rev=0;

    for(int i=0; i<n; i++){
        ListNode *tmp = NULL;
        if(rev+b[i]>=len){
            // reverse from curr to len.
            tmp = curr->next;
            // while(tmp){
            //     cout << tmp->data << " ";
            //     tmp = tmp->next;
            // }
            // cout << endl;
            curr->next = ReverseNodes(curr->next, len-rev);
            if(tmp==head){
                head = curr->next;
            }
            break;
        } else {
            // reverse from curr to curr+b[i].

            int j = b[i];
            ListNode *tmp2 = curr->next;
            while(j--){
                tmp2 = tmp2->next;
            }

            ListNode *th = curr->next;
            curr->next = ReverseNodes(curr->next, b[i]);
            
            if(th==head){
                head = curr->next;
            }

            j = b[i];
            th = curr;
            while(j--){
                th = th->next;
            }

            th->next = tmp2;

            j = b[i];
            while(j--){
                curr = curr->next;
            }

        }

        rev = rev+b[i];
        if(rev>=len) break;
    }

    return head;
}

int main(){
    // Creating a list.
    ListNode *head = CreateList({1, 2, 3, 4, 5});
    int b[] = {0};
    int n = sizeof(b)/sizeof(int);

    ListNode *tmp = ReverseList(head, b, n);
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    return 0;
}
