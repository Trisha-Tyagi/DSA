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
int main(){
    node * root1=nullptr;
    root1=create();
    queue<pair<node*,pair<int,int>>> q;
    map<int, map<int, multiset<int>>> nodes;
    q.push({root1, {0, 0}});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        node * element=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(element->data);
        if(element->left){
            q.push({element->left,{x-1,y+1}});
        }
        if(element->right){
            q.push({element->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> result;
    for(auto p:nodes){
        vector<int> ans;
        for(auto row:p.second){
            for(auto val:row.second){
                ans.push_back(val);

            }

        }
        result.push_back(ans);
    }
    for(auto x:result){
        for(auto r:x){
            cout<<r<<endl;
        }
       
    }
    return 0;
}
