#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void sort012(Node* head){ //TC = O(2N) BECAUSE TWO TIMES TRAVERSAL  //SC=O(1) (BRUTE FORCE APPROACH)
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while(temp!=NULL){
        if(temp->data ==0){
            cnt0++;
        }
        else if(temp-> data ==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp= temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
}

int main(){
    vector<int> arr = {0,1,2,0,1,2};
    Node* head = convertArr2LL(arr);
    sort012(head);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    return 0;
}


