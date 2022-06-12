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

// Time Complexity: O(N+M)
// Space Complexity: O(M);
ListNode* MergeLists(ListNode* first, ListNode* second){
    ListNode *tmp1=NULL, *tmp2=NULL, *ans=NULL;

    // if either one or both lists are empty.
    if(!first) return second;
    if(!second) return first;
    if(!first and !second) return NULL;

    // the list having minimum head will be stored in tmp1 and the other list will be merged in this list only.
    if(first->data > second->data){
        tmp1=second, tmp2=first;
    } else {
        tmp1=first, tmp2=second;
    }

    ans = tmp1;

    // when element of tmp2 is less than element of tmp1 we will insert it in tmp1 at current position.
    while(tmp1->next and tmp2){
        if(tmp1->next->data > tmp2->data){
            ListNode* tmp = tmp1->next;
            tmp1->next = new ListNode(tmp2->data);  // This causes extra use of space.
            tmp1->next->next = tmp;
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }

    // going at the end of answer list
    ListNode *temp = ans;
    while(temp->next){
        temp = temp->next;
    }

    // if tmp2 list is not empty yet, we will add tmp2's all element at the end of tmp1.
    while(tmp2){
        temp->next = tmp2;
        temp = temp->next;
        tmp2 = tmp2->next;
    }

    return ans;

}

int main(){
    // creating list 1...
    ListNode *head1 = new ListNode(1);
    ListNode* temp = head1;
    vector<int> list1 = {5, 11, 14, 25};
    for(int i: list1){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }

    // creating list 2...
    ListNode *head2 = new ListNode(2);
    temp = head2;
    vector<int> list2 = {6, 12, 13, 15};
    for(int i: list2){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }

    // printing the merged list
    temp = MergeLists(head1, head2);
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    delete head1;
    delete head2;
    return 0;
}