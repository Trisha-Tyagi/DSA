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
vector<vector<int>> Zig_Zag(node*root){
    vector<vector<int>> result;
    queue<node*> q;
    q.push(root);
    stack<node*> s;
    int flag=0;
    while(!q.empty()){
        int n=q.size();
        vector<int> a(n,0);
         
            for(int i=0;i<n;i++){
                node* Node = q.front();
                q.pop();
                int index=flag ? i : (n - 1 - i);
                a[index]=Node->data;
                if(Node->left){
                    q.push(Node->left);
                }
                if(Node->right){
                    q.push(Node->right);
                }

            }
             flag=!flag;
            result.push_back(a);
            
        
    }return result;

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
    vector<vector<int>> result=Zig_Zag(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
    }
    return 0;

}