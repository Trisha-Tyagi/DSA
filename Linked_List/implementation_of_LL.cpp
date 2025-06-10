#include<iostream>
#include<algorithm>
struct node{
    int data;
    struct node *next;
};
int main(){
node *head;
node *temp;
head = nullptr;//we can use nullptr instead of 0
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
//accesing data
temp=head;
while(temp!=nullptr){
    std::cout<<temp->data<<" ";
    temp=temp->next;
}



return 0;
}
