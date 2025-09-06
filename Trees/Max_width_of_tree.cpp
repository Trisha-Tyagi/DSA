#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
int  max_width(node *head){
    if(!head) return 0;
    
    int ans=0;
    queue<pair<node*,int>> q;
    q.push({head,0});
    while(!q.empty()){
        int n=q.size();
        int mmin=q.front().second;
        int first,last;
        for(int i=0;i<n;i++){
            node *temp=q.front().first;
            int cur_id=q.front().second-mmin;
            q.pop();
            if(i==0) first=cur_id;
            if(i==n-1) last=cur_id;
            if(temp->left) q.push({temp->left,cur_id*2+1});
            if(temp->right) q.push({temp->right,cur_id*2+2});

        }
        ans=max(ans,last-first+1);
    }
    return ans;
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
    int result=max_width(root);
    cout<<"Max width: "<<result;
    return 0;

}