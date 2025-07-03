#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left,*right;
};

node * create(){
    int x;
    node *newnode =new node;
    cout<<"Enter the value(-1 for no node)";
    cin>>x;
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    cout<<"Enter the left child of node";
    newnode->left=create();
    cout<<"Enter the right child of node";
    newnode->right=create();
    return newnode;
}

node* lca(node* root, int no1, int no2) {
    if (root == nullptr) return nullptr;
    if (root->data == no1 || root->data == no2) return root;
    node* left = lca(root->left, no1, no2);
    node* right = lca(root->right, no1, no2);
    if (left && right) return root;
    return (left != nullptr) ? left : right;
}

int main(){
    node * root1=nullptr;
    root1=create();
    int no1,no2;
    cout<<"enter the value of numbers"<<" ";
    cin>>no1;
    cin>>no2;
    node* least_common_ancestor=lca(root1,no1,no2);
    cout<<"\nLeast common ancestor of "<<no1<<" and "<<no2<<" is "<<least_common_ancestor->data;
    return 0;}