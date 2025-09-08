#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void parent(node *head,unordered_map<node*,node*> &p){
    queue<node*> q;
    q.push(head);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==head) p[temp]=nullptr;
        if(temp->left){
            q.push(temp->left);
            p[temp->left]=temp;
        }
        if(temp->right){
            q.push(temp->right);
            p[temp->right]=temp;
        }
    }
}

vector<int> node_atdistance(node *head,unordered_map<node*,node*> &p,node *target,int k){
    unordered_map<node*,bool> visited;
    queue<node*> que;
    que.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!que.empty()){
        int size=que.size();
        if(curr_level++==k) break;
        for(int i=0;i<size;i++){
            node *first=que.front();
            que.pop();
            if(first->left && !visited[first->left]){
                que.push(first->left);
                visited[first->left]=true;
        }
        if(first->right && !visited[first->right]){
                que.push(first->right);
                visited[first->right]=true;
        }
        if(p[first] && !visited[p[first]]){
            que.push(p[first]);
                visited[p[first]]=true;

        }

        }
        

    }
    vector<int> result;
    while(!que.empty()){
        result.push_back(que.front()->data);
        que.pop();
    }
    return result;

    
}


int main(){
    node*root= new node(9);
    root->left=new node(18);
    root->left->right=new node(86);
    root->right=new node(83);
    root->right->left=new node(89);
    root->right->right=new node(80);
    root->left->right->right=new node(800);
    root->left->left=new node(84);
    root->right->right->right=new node(87);
    unordered_map<node*,node*> p;
    int k=2;
    parent(root,p);
    vector<int> ans=node_atdistance(root,p,root->left->left,k);
    cout<<"At distance "<<k<<"following are nodes\n";
    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}