#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node * next;

    node(int val){
        data=val;
    next=nullptr;
    }
};
node *reverse(node*head){
    if(head==nullptr || head->next==nullptr) return head;
    node*newhead=reverse(head->next);
    head->next->next = head;              
    head->next = nullptr; 
    return newhead;
}
void printll(node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node *head=new node(2);
    head->next=new node(20);
    head->next->next=new node(200);
    head->next->next->next=new node(2000);
    cout<<"Before\n";
    printll(head);
    cout<<"\nAfter\n";
    head=reverse(head);
    printll(head);
    
    return 0;
}