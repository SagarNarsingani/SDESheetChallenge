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

// Time Complexity: O(N).
// Space Complexity: O(N).
bool DetectCycleHash(ListNode *head){
    // if List is empty.
    if(head==NULL) return false;

    unordered_set<ListNode*> s;
    ListNode *tmp = head;
    while(tmp){
        if(s.find(tmp)!=s.end()) return true;
        s.insert(tmp);
        tmp=tmp->next;
    }

    return false;
}

// Flyod's Cycle Detection Algorithm.
// Time Complexity: O(N).
// Space Complexity: O(1).
bool DetectCycle(ListNode *head){
    if(head==NULL) return false;

    ListNode *fast = head, *slow=head;
    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) return true;
    }

    return false;
}

int main(){
    // Creating a list.
    ListNode *head = CreateList({1, 2, 3, 4, 5});
    
    cout << DetectCycleHash(head) << endl;

    // adding cycle in List.
    ListNode *tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = head->next->next;

    cout << DetectCycleHash(head) << endl;

    return 0;
}