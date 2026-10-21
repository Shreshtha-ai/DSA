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

void changeTree(Node* root){
    if(root == NULL) return;
    int child =0;
    if(root->left!=NULL){
        child+=root->left->data;
    }
    if(root->right!=NULL){
        child+=root->right->data;
    }
    if(child>=root->data){
        root->data = child;
    }
    else{
        if(root->left !=NULL){
            root->left->data = root->data;
        }
        else if(root->right !=NULL){
            root ->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);

    int total =0;
    if(root->left!=NULL){
        total+=root->left->data;
    }
    if(root->right!=NULL){
        total+=root->right->data;
    }
    if(root->left!=NULL || root->right!=NULL){
        root->data = total;
    }

}

int main() {
    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(1);

    changeTree(root);

    // Function to print the tree in inorder traversal
    function<void(Node*)> printInorder = [&](Node* node) {
        if (node == NULL) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    };

    cout << "Inorder traversal after changing the tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}