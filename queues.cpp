#include<bits/stdc++.h>
using namespace std;

class Queue{
    int q[10];
    int start,end ;

    public:
    Queue(){
        start = -1;
        end = -1;
    }
    void push(int x){
        if(end<0){
            start++;
            end++;
            q[end]=x;
        }
        else if(end<9){
            end++;
            q[end]=x;
        }
        else{
           cout<< "Queue is overflowing";
        }
    }

    int pop(){
        if(start==-1){
            cout<<"Queue is empty";
            return -1;
        }
        else if(start ==end){
            int x = q[start];
            start =-1;
            end =-1;
            return x;
        }
        else{
            int x = q[start];
            start++;
            return x;
        }
    }
    int peek(){
        if(start ==-1){
            cout<< "Queue is empty";
            return -1;
        }
        else{
            return q[start];
        }
    }

};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
}
