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

// Time Complexity: O(M*N).
// Space Complexity: O(1).
int IntersectionBruteForce(ListNode* firstHead, ListNode *secondHead){
    ListNode *tmp1=firstHead, *tmp2=secondHead;
    // for each node of LL1, we traverse whole LL2.
    while(tmp1){
        while(tmp2){
            if(tmp1==tmp2){
                return tmp1->data;
            }
            tmp2=tmp2->next;
        }
        tmp2 = secondHead;
        tmp1 = tmp1->next;
    }

    return -1;
}

// Time Complexity: O(M+N).
// Space Complexity: O(M). -- size of first LL.
int IntersectionHash(ListNode* firstHead, ListNode *secondHead){
    unordered_set<ListNode *> s;
    // Storing nodes in set.
    while(firstHead){
        s.insert(firstHead);
        firstHead = firstHead->next;
    }

    while(secondHead){
        // checking if node already exists in set.
        if(s.find(secondHead)!=s.end()){
            return secondHead->data;
        }
        secondHead = secondHead->next;
    }

    return -1;
}

// Time Complexity: O(M+N).
// Space Complexity: O(1).
int GetIntersection(ListNode* firstHead, ListNode *secondHead){
    ListNode *tmp1=firstHead, *tmp2=secondHead;

    // Finding length of both LLs.
    int len1=0;
    while(tmp1){
        len1++;
        tmp1 = tmp1->next;
    }
    int len2=0;
    while(tmp2){
        len2++;
        tmp2 = tmp2->next;
    }

    // Finding LL with more length and will reduce extra length from the larger one.
    tmp1=firstHead, tmp2=secondHead;
    if(len1 > len2){
        int diff = len1-len2;
        while(diff--){
            tmp1 = tmp1->next;
        }
    } else {
        int diff = len2-len1;
        while(diff--){
            tmp2 = tmp2->next;
        }
    }

    // Now we can move pointers togather on both LLs.
    while(tmp1){
        if(tmp1==tmp2){
            return tmp1->data;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return -1;
}

int main(){

    // creating 3 Linked Lists.
    ListNode *ls1 = CreateList({1, 4, 5});
    ListNode *ls2 = CreateList({2, 4, 6});
    ListNode *ls3 = CreateList({7, 8, 9, 10});

    // initially there is no intersection.
    cout << GetIntersection(ls1, ls2) << endl;
    
    // Merging first and second LL at Third LL.
    ListNode *tmp1 = ls1, *tmp2 = ls2;
    while(tmp1->next){
        tmp1 = tmp1->next;
    }
    while(tmp2->next){
        tmp2 = tmp2->next;
    }
    tmp1->next = ls3;
    tmp2->next = ls3;

    // To print LL1 and LL2.
    // tmp1 = ls1;
    // while(tmp1){
    //     cout << tmp1->data << " ";
    //     tmp1 = tmp1->next;
    // }
    // cout << endl;
    // tmp2 = ls2;
    // while(tmp2){
    //     cout << tmp2->data << " ";
    //     tmp2 = tmp2->next;
    // }

    // answer: 7.
    cout << IntersectionHash(ls1, ls2);

    return 0;
}