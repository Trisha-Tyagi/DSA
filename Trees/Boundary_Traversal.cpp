#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void left(Node *root,vector<int> &arr){
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr) return;
    arr.push_back(root->data);
    if(root->left) left(root->left,arr);
    else left(root->right,arr);
    return;
}
void right(Node *root,stack<int> &st){
    
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr) return;
    st.push(root->data);
    if(root->right) right(root->right,st);
    else right(root->left,st);
    return;
}
void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void preorder(Node *root,vector<int> &arr){
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr){
        arr.push_back(root->data);
        return;}
    if(root->left) preorder(root->left,arr);
    if(root->right) preorder(root->right,arr);
    return;
}
int main(){
    Node* root = new Node(1);
    vector<int> result;
    stack<int> st;
    // Left side
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(9);
    root->left->left->right->right = new Node(10);
    root->left->left->right->left->left = new Node(12);
    root->left->left->right->left->right = new Node(13);
    root->left->left->right->right->right = new Node(14);

    // Right side
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(8);
    root->right->right->right->right=new Node(11);
    result.push_back(root->data);
    //left traversal
    left(root->left,result);
    //for roots
    preorder(root,result);
    //right traversal
    right(root->right,st);
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    print(result);
    return 0;
}