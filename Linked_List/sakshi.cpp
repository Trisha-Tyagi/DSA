#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main(){
    node *head,*temp;
    head = temp = nullptr ;
    int choice = 0;
     node *newnode = new node;
    cout<<"Do u want to insert?(0/1)";
    cin>>choice;

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

    

    temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }


    // Insert at a specific place

    // node *newnode = new node;
    cout<<"Enter data:";
    cin>>newnode->data;
    newnode->next = nullptr;
    temp = head;

    int pos;
    cout<<"At which position u want to insert";
    cin>>pos;
    int i = 0;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

     temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

// deletion

  cout<<"Enter the position u want to delete:";
  cin>>pos;
  i = 0;
  temp = head;
  while(i<pos-1){
    temp=temp->next;
    i++;
  }

   node *temp1 = temp->next;

   temp->next = temp->next->next;
   temp1->next = nullptr;


   temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }



    return 0;

}
