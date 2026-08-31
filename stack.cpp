#include<bits/stdc++.h>
using namespace std;

class Stack{
    int stack[5];
    int top;

    public:
    Stack() {
        top = -1;

    }
    void push(int x){
        if(top<4){
            top++;
        stack[top]=x;
        }
        else{
            cout<< "stack is overflowing";
        
        }

    }
    int pop(){

        if(top == -1){
            cout<< "Stack is empty";
            return -1 ;
        }
        int x = stack[top];
        top --;
        return x;
    }

    int peek(){
        if(top ==-1){
            cout<< "Stack is empty";
            return -1;

        }
        return stack[top];
    }

};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout<< s.peek() << endl;

    



}



    