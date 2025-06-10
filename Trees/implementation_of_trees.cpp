#include<iostream>
#include<vector>
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
bool isIdentical(node *root1,node* root2){
    if(root1==nullptr || root2==nullptr) return(root1==root2);
    if(root1->data!=root2->data){
        return false;
    }
    isIdentical(root1->left,root2->left);
    isIdentical(root1->right,root2->right);

}


int main(){
    node * root2=nullptr;
    node * root1=nullptr;
    root1=create();
    root2=create();
    bool ret=isIdentical(root1,root2);
    cout<<ret;

    return 0;
    
}
