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
Node* deleteKth(Node* head, int k){
    if(head ==nullptr){
        return NULL;
    }
    int cnt =0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev ==NULL && front ==NULL){
        return nullptr;
    }
    if(prev ==NULL){
        head = front;
        front->back = nullptr;
        delete temp;
        return head;
    }
    if(front ==NULL){
        prev->next = nullptr;
        delete temp;
        return head;
    }

    prev->next = front;
    front->back = prev;
    delete temp;
    return head;
    
}
int main(){
    int n,k;
    cout<<"Enter the number of ellement of array:";
    cin>> n;
    vector<int> arr(n);
    cout<<"Enter the ellement of array:";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    Node* head = convertArr2DLL(arr);
    cout<<"Enter the position of ellement to be deleted:";
    cin>> k;
    head = deleteKth(head,k);
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}