#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* insertionsort(Node* head){
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data >=prev->data){
            prev = curr;
            curr = curr->next;
        }
        else{
            Node* temp = curr->next;
            prev->next = curr->next;
            
            
        }
    }
    
}
