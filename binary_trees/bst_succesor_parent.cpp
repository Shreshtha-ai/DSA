#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* p;  // Parent pointer

    Node(int value) {
        key = value;
        left = right = p = nullptr;
    }
};

Node* treeMin(Node* node){
    while(node->left!= nullptr){
        node = node->left;
    }
    return node;
}

Node* Successor(Node* x){
    if(x==nullptr){
        return nullptr;
    }

    if(x->right!=nullptr){
        return treeMin(x->right);
    }

    Node*y = x->p;

    while(y!=nullptr && x == y->right){
        x=y;
        y = y->p;
    }
    return y;

}
