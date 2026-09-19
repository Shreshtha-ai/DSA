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
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp; // it basically means that the next of the current node is pointing to the newly created node before it was pointing to null
        mover = temp;
    }
    return head;
}

Node* removetail(Node* head){
    if(head ==nullptr || head->next ==nullptr) return nullptr;

    Node* temp = head;
    while(temp->next->next !=nullptr){
        temp = temp->next;
    }
    delete temp->next; //diffrence between delete and free is delete is c++ specific while free is c specific 
    temp->next = nullptr;

    return head;

    
}

int main(){
    vector<int> arr = {2,4,5,6,712};
    Node* head = convertArr2LL(arr);
    head = removetail(head);
    Node* mover = head;
    while(mover!=nullptr){
        cout<<mover->data;
        mover = mover->next;
    }
} 