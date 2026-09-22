#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
}; 

class Myqueue{
    private:
    Node* start;
    Node* end;
    int count;
    public:
    Myqueue(){
        start = NULL;
        end = NULL;
        count = 0;
    }

    void push(int value){
        Node* newNode = new Node(value);
        if(start ==NULL){
            start = newNode;
            end = newNode;
        }
        else{
            end->next = newNode;
            end = newNode;
        }
        count++;
    }
    int pop(){
        if(start ==NULL){
            return -1;
        }
        Node* temp = start;
        start = start->next;
        count--;
        delete temp;
        return temp->data;
    }

    int peek(){
        if(start == NULL){
            return -1;
        }
        return start->data;
    }
    bool isEmpty(){
        return start==NULL;
    }
    int size(){
        return count;
    }
    


};

int main(){
    Myqueue q1;
    q1.push(2);
    q1.push(7);
    q1.push(8);
    cout<<q1.pop()<<endl;
    cout<<q1.peek()<<endl;
    cout<<q1.size()<<endl;
    cout<<(q1.isEmpty() ? "Empty" : "Not Empty")<<endl;
    return 0;
}

//TC = O(1)
//SC = O(1)