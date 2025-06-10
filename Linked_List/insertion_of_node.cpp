#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;

};
int main(){
    node *newnode=new node;//use in inserting 
    node  *head,*temp;
    head=0;
    int choice =1;
while(choice){
node *newnode=new node;
std::cout<<"Enter the value"<<" ";
std::cin>>newnode->data;
newnode->next=nullptr;
if(head ==nullptr){
    head=temp=newnode;
}
else{
    temp->next=newnode;
    temp=newnode;
}
std::cout<<"Do you want to insert more nodes(1/0)";
std::cin>>choice;
}
// accesing data
temp=head;
while(temp!=nullptr){
    std::cout<<temp->data<<" ";
    temp=temp->next;
}


// //insertion of a node in the beginning
//     cout<<"enter the data"<<" ";
//     cin>>newnode->data;
//     newnode->next = head;
//     head =newnode;

// //insertion of  a node in the end
// temp=head;
// while(temp->next!=0){
//     temp=temp->next;
// }
// cout<<"enter the value ";
// cin>>newnode->data;
// temp->next=newnode;
// newnode->next=0;

// insert the element at a specific position
int ch=0;
temp=head;
cout<<temp;
int position;
std::cout<<"at which position u want to add element";
cin>>position;
while(ch<position-1){
    // if(ch==position){
    //     break;
    // }
    temp=temp->next;
    ch++;
}



cout<<"enter the value ";
cin>>newnode->data;
// temp->next=newnode;
// temp=temp->next;
// newnode->next=temp;
newnode->next=temp->next;
temp->next=newnode;



//accesing data
temp=head;
while(temp!=nullptr){
    std::cout<<temp->data<<" ";
    temp=temp->next;
    }
    
    return 0;
}