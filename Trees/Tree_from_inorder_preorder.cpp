#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=right=nullptr;
    }
};
void display(struct node* head){
    if(head==nullptr){
        return ;
    }
    struct node* temp=head;
    cout<<temp->data<<" ";
    if(temp->left) display(head->left);
    if(temp->right) display(head->right);
    return;
}

void printInorder(node* head) {
    if (head == nullptr) return;
    printInorder(head->left);
    cout << head->data << " ";
    printInorder(head->right);
}
node *construct(vector<int> preorder,int pstart,int pend,vector<int> inorder,int istart,int iend,map<int,int> dic){
    if(pstart > pend || istart > iend) return nullptr;
    int n=inorder.size();
    int m=preorder.size();
    int element=preorder[pstart];
    struct node* new_node=new node(element);
    int i=dic[element];
    int numdiff=dic[element]-istart;
    new_node->left=construct(preorder,pstart+1,pstart+numdiff,inorder,istart,i-1,dic);
    new_node->right=construct(preorder,pstart+1+numdiff,pend,inorder,i+1,iend,dic); 
    return new_node;


}
int main(){
    vector<int> inorder={40,20,50,10,60,30};
    vector<int> preorder={10,20,40,50,30,60};
    int n=inorder.size();
    int m=preorder.size();
    map<int,int> dic;
    for(int i=0;i<n;i++){
        dic[inorder[i]]=i;
    }
    node *head=construct(preorder,0,m-1,inorder,0,n-1,dic);
    cout<<"Tree built!!\n";
    cout<<"Preorder ";
    display(head);
    cout<<"\nInorder "; 
    printInorder(head);
    return 0;

}
