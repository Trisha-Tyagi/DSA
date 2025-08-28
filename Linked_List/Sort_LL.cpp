#include<iostream>
using namespace std;
struct node{
    int data;
    node *next=nullptr;

    node(int val){
        data=val;
        next=nullptr;
    }

};
node* merge_ss_ll(node *left,node* right){
    node*dummy_node=new node(-1);
    node*temp=dummy_node;
    while(left!=nullptr && right!=nullptr){
        if(left->data>=right->data){
            temp->next==left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    if(left){
        temp->next=left;
        left=left->next;
    }
    else{
        temp->next=right;
        right=right->next;
    }
    return dummy_node->next;
}
node *split(node *head){
    if( head==nullptr || head->next==nullptr) return head;
    node*slow=head;
    node*fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

    }
    node*left=head;
    node*right=slow->next;
    slow->next=nullptr;
    left=split(left);
    right=split(right);
    return merge_ss_ll(left,right);

}
void printLL(node *head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node *head=new node(8);
    head->next=new node(80);
    head->next->next=new node(800);
    head->next->next->next=new node(8000);
    head->next->next->next->next=new node(80000);
    cout<<"Linked List: \n";
    printLL(head);
    head=split(head);
    cout<<"\nsorted LL:\n";
    printLL(head);
    return 0;
}