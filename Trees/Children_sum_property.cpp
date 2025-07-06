#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left,*right;
};
node* create(){
    int x;
    cout<<"Enter the value(-1 for no node)";
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    node *newnode =new node;
    newnode->val=x;
    cout<<"Enter the left child of node";
    newnode->left=create();
    cout<<"Enter the right child of node";
    newnode->right=create();
    return newnode;

}

int traversal(node* root) {
    if (root == NULL)
        return 0;

    // Recur for left and right subtrees
    int left = traversal(root->left);
    int right = traversal(root->right);
    int result = left + right;

    if (root->val < result) {
        int to_add = result - root->val;
        root->val += to_add; // Pull up value
    } 
    else if (root->val > result) {
        int to_add = root->val - result;

        // Push excess down — to left first, then right
        node* child = root;
        while (child != NULL && (child->left || child->right)) {
            if (child->left != NULL) {
                child->left->val += to_add;
                child = child->left;
            } 
            else if (child->right != NULL) {
                child->right->val += to_add;
                child = child->right;
            }
        }
    }

    // Return updated value of the current root
    return root->val;
}
void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main(){
    node *root=create();
    int result = traversal(root);
    cout << "Binary Tree after Children Sum Property: " ;
    inorder(root);
    cout << endl;
    return 0;}