#include <iostream>
#include <vector>
#include <stack>
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
// Space Complexity: O(N).
bool isPalindromeStack(ListNode *head){
    // finding length.
    ListNode *tmp = head;
    int len=0;
    while(tmp){
        len++;
        tmp = tmp->next;
    }

    // if length is less than two then list is palindrome.
    if(len < 2) return true;

    // using stack to check palindrome.
    stack<int> s;
    tmp=head;
    int i=0;
    while(tmp){
        // if length is odd we won't push element in stack.
        if(len&1 and i==len/2) {
                tmp = tmp->next;
                i++;
                continue;
        }
        if(i<len/2){
            s.push(tmp->data);
        } else {
            if(tmp->data==s.top()){
                s.pop();
            } else {
                return false;
            }
        }
        i++;
        tmp = tmp->next;
    }
    return true;
}

ListNode *Reverse(ListNode *head){
    ListNode *prev=NULL, *curr=head;
    if(head==NULL) return NULL;
    while(curr){
        ListNode *tmp = curr; 
        curr = curr->next;
        tmp->next = prev;
        prev = tmp;
    }

    return prev;
}

bool isPalindrome(ListNode *head){
    if(head==NULL or head->next==NULL) return true;

    ListNode *fast=head, *slow=head;
    while(fast->next and fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = Reverse(slow->next);

    ListNode *p1=head, *p2=slow->next;
    while(p2){
        if(p1->data != p2->data){
            return false;
        }
        p2=p2->next;
        p1=p1->next;
    }
    return true;
}
int main(){
    ListNode *head = CreateList({2, 3});
    cout << isPalindrome(head);

    return 0;
}