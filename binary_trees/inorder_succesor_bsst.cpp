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

Node* inorderSuccessor(Node* root, Node* x){
    Node* successor = nullptr;
    while(root){
        if(x->data < root->data){
            successor = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return successor;
}