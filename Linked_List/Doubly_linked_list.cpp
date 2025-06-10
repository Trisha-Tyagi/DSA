#include<iostream>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;

};
int main(){
    node *head,*temp;
    int choice=1;
    head=nullptr;
    while(choice){
        node *newnode=new node;
        cout<<"enter data"<<" ";
        cin>>newnode->data;
        if(head==nullptr){
            head=temp=newnode;
        }
        else{
            newnode->prev=temp;
            newnode->next=0;
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"Do you want to enter more data(0/1)";
        cin>>choice;
    };

    temp=head;
    while(temp!=0){
        cout<<temp->data<<endl;
        temp=temp->next;
    };

    return 0;
}