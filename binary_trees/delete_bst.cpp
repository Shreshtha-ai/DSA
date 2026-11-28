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

Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->val == key){
        return helper(root);
    }
    Node* temp = root;
    while(root!=NULL){
        if(root->val>key){
            if(root->left!=NULL && root->left->val == key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->val == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }

        }
    }
    return temp;    
}

Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* lastRight = findlastRight(root->left);
    lastRight->right = rightChild;
    return root->left;

}

Node* findlastRight(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findlastRight(root->right);
}

