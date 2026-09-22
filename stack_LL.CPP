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

class Stack{
    private:
    Node* top;
    public:
    int count;
    Stack(){
        top = NULL;
        count = 0;
    }

    void push(int value){
        Node* newNode = new Node(value);

        newNode -> next = top;
        top = newNode;
        count++;
    }
    int pop(){
        if(top ==NULL){
            return -1;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return temp->data;
    }
    int peek(){
        if(top == NULL){
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
    int size(){
        return count;
    }
};

int main(){

    Stack s;
    s.push(2);
    s.push(7);
    s.push(8);
    cout<<s.pop()<<endl ;
    cout<<s.peek()<<endl ;
    cout<<(s.isEmpty()?"empty":"not empty")<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<(s.isEmpty()?"empty":"not empty")<<endl;
    cout<<s.size();

    return 0;
}

//TC = O(1)
//SC = O(1)
