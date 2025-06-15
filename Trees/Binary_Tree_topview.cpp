#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
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
    newnode->data=x;
    cout<<"Enter the left child of node";
    newnode->left=create();
    cout<<"Enter the right child of node";
    newnode->right=create();
    return newnode;

}

int main(){
    node *root=create();
    queue<pair<node *,int>> q;
    map<int,int> d;
    q.push({root,0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        node *currnode=curr.first;
        int x=curr.second;
        if(d.find(x)==d.end()){
            d[x]=currnode->data;
        }
        if(currnode->left!=nullptr) q.push({currnode->left,x-1});
        if(currnode->right!=nullptr) q.push({currnode->right,x+1});

    }
    for(auto it:d){
        cout<<it.second<<endl;
    }
    return 0;
    

}