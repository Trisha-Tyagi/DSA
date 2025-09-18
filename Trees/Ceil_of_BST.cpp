#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node* right;

    Node(int val){
        data=val;
        left=right=nullptr;
    }

};

void ceil(Node* root,int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            break;
        }
        if(root->data<key){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    if(ceil==-1){
        cout<<"no ceil found.";

    }
    else{
        cout<<ceil;
    }
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    root->right->right->right = new Node(10);

    cout<<"Ceil of 4 is : ";
    ceil(root,4);

}