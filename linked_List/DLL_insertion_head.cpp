#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
    
}
Node* insertHead(Node*head, int data){
    Node *newHead = new Node(data,head,nullptr);
    head->back = newHead;
    return newHead;
}
Node* insertAfterHead(Node*head, int data){
    Node* newHead = new Node(data, head->next,head);
    head->next->back = newHead;
    head->next = newHead;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2DLL(arr);
    head = insertHead(head,10);
    head = insertAfterHead(head,20);
    while(head!=nullptr){
        cout<<head->data<< " ";
        head = head->next;
    }
    return 0;
}