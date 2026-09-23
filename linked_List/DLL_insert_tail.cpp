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
Node* insertbeforeTail(Node* head, int data){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(data,tail,prev);
    prev->next = newNode;
    tail->back = newNode;

    return head;
}
Node* insertafterTail(Node* head,int data){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* newNode = new Node(data,nullptr,tail);
    tail->next = newNode;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2DLL(arr);
    head = insertbeforeTail(head,20);
    head = insertafterTail(head,30);
    while(head!=nullptr){
        cout<<head->data<< " ";
        head = head->next;
    }
    return 0; 
}