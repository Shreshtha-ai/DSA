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
Node* insertK(Node* head,int val,int k){
    if(head == nullptr){
        if(k==1){
            return new Node(val);
        }else{
            return nullptr;
        }

    }
    if(k==1){
        Node* temp = new Node(val,head);
        return temp;
    }
    int cnt =0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        cnt++;
        if(cnt ==k-1){
            Node* newNode = new Node(val);
            newNode-> next = temp->next;
            temp->next = newNode;
            break;

        } 
        temp = temp->next;
        
    }
    return head; 
}
int main(){
    vector<int> arr = {2,4,5,6,712};
    Node* head = convertArr2LL(arr);
    head = insertK(head,100,3);
    Node* mover = head;
    while(mover!=nullptr){
        cout<<mover->data<< " ";
        mover = mover->next;
    }
} 


