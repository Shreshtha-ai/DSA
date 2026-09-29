#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

pair<Node*, Node*> splitinTwo(Node* head){
    Node* slow = head; //as when fast will reach end slow will reach midway because fast is twice faster then slow pointer 
    Node* fast = head;

    if(head==NULL || head->next ==NULL) return head;
    while(fast->next!=head && fast->next->next!=head) 
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* head2 = slow->next;
    slow->next = head;
    fast->next = head2;

    return {head2, head};
}

