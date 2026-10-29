#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int floorBST(Node* root, int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            return root->data;
        }
        else if(root->data>key){
            root = root->left;    
        }
        else{
            floor = root->data;
            root = root->right;
            
        }
    }
    return floor;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key;
    cin>>key;
    cout<<floorBST(root, key)<<endl;
    return 0;
}
