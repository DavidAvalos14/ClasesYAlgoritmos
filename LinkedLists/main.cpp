#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLista(ListNode* lista) {
    ListNode* p = lista;

    while(p) {
        cout << p->val << " ";
        p = p->next;
    }

    cout << endl;
}

int main() {
    // 3 2 0 -4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next  = new ListNode(3);
    head->next->next->next  = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    if(!head || !head->next) printLista(head);

    ListNode* ptr1 = head;
    head = head->next;
    ListNode* ptr2 = head;

    ptr1->next = nullptr;

    while(head) {
        ptr2->next = ptr1;
        head = head->next;
        ptr1 = ptr2;
        ptr2 = head;
    }

    printLista(ptr1);

    return 0;
}