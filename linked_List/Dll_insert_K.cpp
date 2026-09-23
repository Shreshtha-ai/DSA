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
Node* insertBeforeKth(Node* head,int data,int k){
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    if(prev == nullptr){
        Node* newHead = new Node(data,head,nullptr);
        head->back = newHead;
        return newHead;
    }
    Node* newNode = new Node(data,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
    
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2DLL(arr);
    int k;
    cout<<"Enter the position of ellement to be inserted:";
    cin>> k;
    int data;
    cout<<"Enter the ellement to be inserted:";
    cin>> data;
    head = insertBeforeKth(head,data,k);
    while(head!=nullptr){
        cout<<head->data<< " ";
        head = head->next;
    }
    return 0;
}