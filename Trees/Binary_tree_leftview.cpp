#include<iostream>
#include<vector>
using namespace std;
struct Treenode{
    int data;
    Treenode *left,*right;
};

Treenode* create(){
    int x;
    cout<<"Enter the value(-1 for no node)";
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    Treenode *newnode =new Treenode;
    newnode->data=x;
    cout<<"Enter the left child of node  ";
    newnode->left=create();
    cout<<"Enter the right child of node  ";
    newnode->right=create();
    return newnode;
}
vector<int> traversal(Treenode *root,int level,vector<int>& ds){
    if(root==nullptr) return ds;
    if(ds.size()==level) ds.push_back(root->data);
    if(root->right){
        traversal(root->right,level+1,ds);
    }
    if(root->left){
        traversal(root->left,level+1,ds);
    }
    return ds;
}
int main(){
    Treenode *root=create();
    vector<int> result;
    result=traversal(root,0,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
