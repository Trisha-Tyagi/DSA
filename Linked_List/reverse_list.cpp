#include<iostream>
using namespace std;
struct node{
    int data;
    node *next ;
};
int main(){
    node *head,*temp;
    head = temp = nullptr ;
    int choice = 0;
     node *newnode = new node;
    cout<<"Do u want to insert?(0/1)";
    cin>>choice;
     node *prevnode,*nextnode;
    while(choice){
        int s = 1;//can't use this value outside the block/loop
        node *newnode = new node;
        cout<<"Enter data:";
        cin>>newnode->data;

        newnode->next = nullptr;

        if(head==nullptr){
            head=temp=newnode;
        }

        else{
            temp->next = newnode;
            temp = newnode;

        }
    cout<<"Do u want to insert?(0/1)";
    cin>>choice;
        
    }

    
    temp=nextnode=head;//don't write temp=head=nextnode
    prevnode=nullptr;
    while(nextnode!=nullptr){
        nextnode=temp->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    head=prevnode;

    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
return 0;
}

