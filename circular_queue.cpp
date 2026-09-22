#include<bits/stdc++.h>
using namespace std;

class Circularqueue{
    int q[12];
    int start,end;
    public:
    Circularqueue(){
        start = -1;
        end = -1;
    }
    void push(int x){
        if((end+1)%12==start){
            cout<<"Queue is overflowing"<<endl;
            return;
        }
        if(start ==-1){
            start=0;
            end=0;
            q[end]=x;
        }
        else{
            end=(end+1)%12;
            q[end]=x;
        }
    }
    int pop(){
        if(start == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x = q[start];
        if(start ==end){
            start = -1;
            end = -1;
        }
        else {
            start = (start+1) %12;
        }
        return x;
    }
    int peek(){
        if(start == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return q[start];
        }
    }

    bool isEmpty(){
        return start == -1;
    }
    


};

int main(){
    Circularqueue c;
    c.push(2);
    c.push(7);
    c.push(8);
    c.push(10);

    cout<<c.pop()<<endl;
    cout<<c.peek()<<endl;
    cout<<c.pop()<<endl;
    cout<<c.pop()<<endl;
    cout<<c.pop()<<endl;
    c.push(10);
    cout<<c.pop()<<endl;
    cout<<(c.isEmpty() ? "Empty" : "Not Empty")<<endl;
    return 0;
}


