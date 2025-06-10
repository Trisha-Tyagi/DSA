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

    // temp=head;
    // while(temp!=0){
    //     cout<<temp->data<<endl;
    //     temp=temp->next;
    // };
    // //insert new data
    // temp=head;
    // int pos=0;
    // cout<<"enter the position";
    // cin>>pos;
    // int temp1=0;
    // while(temp1<pos-1){
    //     temp=temp->next;
    //     temp1++;
    // };
    // node *newnode=new node;
    // cout<<"enter data";
    // cin>>newnode->data;
    // newnode->prev=temp;
    // newnode->next=temp->next;
    // temp->next=newnode;
    // newnode->next->prev=newnode;

    // //displaying data
    // temp=head;
    // while(temp!=0){
    //     cout<<temp->data<<endl;
    //     temp=temp->next; 
    // };
    // deletion of a node
    // temp=head;
    // int pos_del=0;
    // int temp1=0;
    // cout<<"which position element wanna del";
    // cin>>pos_del;
    // while(temp1<pos_del-1){
    //     temp=temp->next;
    //     temp1++;
    // }
    // node *temp2=temp->next;
    // temp->next=temp2->next;
    // temp2->next->prev=temp;
    // temp=head;
    // while(temp!=0){
    //     cout<<temp->data<<endl;
    //     temp=temp->next;
    // };
    //reversing of a list
    temp=head;
    while(temp->next!=0){
        temp=temp->next;

    }
    head=temp;

    temp=head;
    while(temp!=0){
        cout<<temp->data<<endl;
        temp=temp->prev;
    };


    return 0;
}