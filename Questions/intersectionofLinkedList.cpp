#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x): val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) 
        return NULL;

    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b) {
        if (!a) {
            a = headB;
        } else {
            a = a->next;
        }

        if (b == NULL) {
            b = headA;
        } else {
            b = b->next;
        }
    }
    return a;
}

ListNode* insert(ListNode* head, int x) {
    ListNode* newNode = new ListNode(x);
    if (head == NULL) {
        return newNode;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printLL(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode *headA = new ListNode(1);
    insert(headA, 2);
    insert(headA, 3);
    ListNode *headB = new ListNode(4);
    insert(headB, 5);
    
    ListNode* intersectNode = new ListNode(6);
    headA->next->next->next = intersectNode;
    headB->next->next = intersectNode;
    
    insert(intersectNode, 7);
    insert(intersectNode, 8);

    printLL(headA);
    printLL(headB);

    
    ListNode* intersection = getIntersectionNode(headA, headB);
    cout<<intersection->val;
}
