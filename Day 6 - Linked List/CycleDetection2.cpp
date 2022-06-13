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
// Space Complexity: O(1).
int DetectCycle(ListNode *head){
    if(head==NULL) return -1;

    ListNode *fast = head, *slow=head;
    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) {
            int i=0;
            // L1 = C - L2.
            // C -- Length of Cycle.
            // L1 -- Distance of Start Node to Starting Node of Cycle.
            // L2 -- Distance between Starting point of cycle to Collision node of Fast and Slow. 
            while(head!=slow){
                slow = slow->next;
                head = head->next;
                i++;
            }
            return i;
        };
    }

    return -1;
}

int main(){
    // Creating a list.
    ListNode *head = CreateList({1, 2, 3, 4, 5});

    // adding cycle in List.
    ListNode *tmp = head;
    while(tmp->next){
        tmp = tmp->next->next;
    }
    tmp->next = head->next;

    cout << DetectCycle(head) << endl;

    return 0;
}