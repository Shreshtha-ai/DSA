#include<bits/stdc++.h>
using namespace std;
class Node{ // if we use struct instead of class then we dont get oop concepts like encapsulation and data hiding
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int> arr = {2,4,5,6,712};
    Node* y = new Node{arr[0], nullptr};
    cout<< y->data;
}