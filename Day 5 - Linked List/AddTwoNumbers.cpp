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

ListNode *AddTwoNums(ListNode* head1, ListNode* head2){
    
    ListNode* sum = new ListNode(-1), *num1=head1, *num2=head2;
    int tmp = 0;
    ListNode* tempSum = sum;

    while(num1 and num2){
        int curr = num1->data + num2->data + tmp;
        tmp = curr/10;
        curr = curr%10;
        ListNode *temp = new ListNode(curr);
        tempSum->next = temp;
        tempSum = tempSum->next;
        num1 = num1->next;
        num2 = num2->next;
    }

    while(num1){
        int curr = num1->data + tmp;
        tmp = curr/10;
        curr = curr%10;
        ListNode *temp = new ListNode(curr);
        tempSum->next = temp;
        tempSum = tempSum->next;
        num1 = num1->next;
    }
    
    while(num2){
        int curr = num2->data + tmp;
        tmp = curr/10;
        curr = curr%10;
        ListNode *temp = new ListNode(curr);
        tempSum->next = temp;
        tempSum = tempSum->next;
        num2 = num2->next;
    }

    if(tmp!=0){
        ListNode *temp = new ListNode(tmp);
        tempSum->next = temp;
        tempSum = tempSum->next;
    }

    return sum->next;
}
int main(){
    // creating list 1...
    ListNode *num1 = new ListNode(5);
    ListNode* temp = num1;
    vector<int> arr1 = {1, 0, 6};
    for(int i: arr1){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }



    // creating list 2...
    ListNode *num2 = new ListNode(6);
    temp = num2;
    vector<int> arr2 = {7, 3, 4};
    for(int i: arr2){
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = node;
    }

    // printing the merged list
    temp = AddTwoNums(num1, num2);
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    delete num1;
    delete num2;
    return 0;
}