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

Node* inorderpredecessor(Node* root, Node* x){
    Node* predecessor = nullptr;

    while(root){
        if(x->data >root->data){
            predecessor = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }