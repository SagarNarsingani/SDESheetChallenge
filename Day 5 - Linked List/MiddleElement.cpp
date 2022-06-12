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

// Time Complexity: O(N)
// Space Complexity: O(N).
int GetMiddleElement(ListNode *head){
    // Finding total length first...
    int len=0;
    ListNode* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }

    // calculating mid.
    int mid = ceil((float) len/2);
    if(!(len&1)) mid++; // if even we need to return farthest one.
    
    // finding middle element.
    int curr = 1;
    temp=head;
    while(temp){
        if(curr==mid){
            return temp->data;
        }
        temp = temp->next;
        curr++;
    }
    
    // just to avoid warning while compilation.
    return -1;
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

    cout << GetMiddleElement(head);

    delete head;
    return 0;
}