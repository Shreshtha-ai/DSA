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

Node* make_circle(Node* head, int n){
    for(int i=1;i<=n;i++){
        Node* nn = new Node(i);
        if(head==NULL){
            head = nn;
            
        }
        else{
            Node* r = head;
            while(r->next!=head){
                r = r->next;
            }
            r->next = nn;
           
        }
        nn->next = head;
    }
    return head;
}

void find_it( Node* head, int counter, int k){

    Node* p = head, *q; 
    for(int i=1;i<counter;i++){
        p = p->next;
    }
        while(p->next!=p){
            for(int j=0;j<k-1;j++){
                q=p;
                p = p->next;


            }
            q->next = p->next;
            delete p;
            p = q->next;


        }
        cout <<"child who become it is "<<p->data<<endl;
        
    }

int main(){
    int n,k,counter;
    cin>>n>>k>>counter;
    Node* head = NULL;
    head = make_circle(head,n);
    find_it(head,counter,k);
    return 0;
}


