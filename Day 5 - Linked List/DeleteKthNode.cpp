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

ListNode *DeleteKthNode(ListNode *head, int k){
    ListNode *tmp = head;
    int len = 0;
    while(tmp){
        tmp=tmp->next;
        len++;
    }

    if(len==0) return NULL;

    if(len==k-1){
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    if(k==1){
        if(len==1) return NULL;
        tmp=head;
        while(tmp->next->next){
            tmp = tmp->next;
        }
        tmp->next = NULL;
        delete tmp->next;
        return head;
    }

    tmp=head;
    int curr=1;
    while(tmp){
        if(curr==(len-k+1)){
            tmp->data=tmp->next->data;
            tmp->next = tmp->next->next;
            return head;
        }
        tmp=tmp->next;
        curr++;
    }

    return head;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode* temp = head;

    // creating list
    vector<int> arr = {5, 98, 8, 2, 2, 5};
    for(int i: arr){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }

    ListNode *n = new ListNode(1);
    temp = DeleteKthNode(n, 1);

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout <<"k" ;
    delete head;
    return 0;
}