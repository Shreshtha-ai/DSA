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

Node* removeK(Node* head, int k){
    if(head == nullptr || k ==0){
        return head;
    }
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;

    }
    int cnt =0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp !=nullptr){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            delete temp;
            break;

        }
        prev = temp;
        temp = temp->next;
        
    }
    return head;

    

    
}

int main(){
    vector<int> arr = {2,4,5,6,712};
    Node* head = convertArr2LL(arr);
    head = removeK(head,3);
    Node* mover = head;
    while(mover!=nullptr){
        cout<<mover->data;
        mover = mover->next;
    }
} 