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
vector<vector<int>> prePostInorder(Node* root){
    stack<pair<Node*, int>> st;
    vector<int> pre, in, post;
    st.push({root,1});
    if(root == NULL) return {};

    while(!st.empty()){
        pair a = st.top();
        st.pop();
        if(a.second ==1){
            pre.push_back(a.first->data);
            a.second++;
            st.push(a);
            if(a.first->left != NULL){
                st.push({a.first->left,1});
            }
        }
        else if(a.second ==2){
            in.push_back(a.first->data);
            a.second++;
            st.push(a);
            if(a.first->right != NULL){
                st.push({a.first->right,1});
            }
        }
        else{
            post.push_back(a.first->data);
        }

    }
    return {pre, in, post};
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    vector<vector<int>> result = prePostInorder(root);

    cout << "Preorder: ";
    for (int x : result[0]) cout << x << " ";

    cout << "\nInorder: ";
    for (int x : result[1]) cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : result[2]) cout << x << " ";

    return 0;
}