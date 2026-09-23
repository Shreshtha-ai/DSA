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
Node* convertarr2CLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
    return head;
}
Node* searchCll(Node* head, int val){
    if(head==NULL) return NULL;
    Node* temp = head;
    while(temp->next!=head && temp->data !=val){
        temp = temp->next;
    }
    if(temp->data==val){
        return temp;
    }
    return NULL;
}
void display(Node* head){
    Node* temp = head;
    if(head ==NULL) return;
    while(temp->next!=head){  
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    cout<<temp->data; // this prints last node because condition in while loop stops before last node 
}

Node* insertHead(Node* head, int val){
    Node* newNode = new Node(val);
    Node* temp = head;
    if(head ==NULL){
        return newNode;
    }
    
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}


int main(){
    vector<int> arr = {1,5,6,2,3,6,9};
    Node* head = convertarr2CLL(arr);
    head = insertHead(head,20);
    display(head);
    Node* temp = searchCll(head,9);
    if(temp!=NULL){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }
    return 0;

    
}



