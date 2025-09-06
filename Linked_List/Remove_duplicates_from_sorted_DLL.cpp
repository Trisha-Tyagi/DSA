#include<iostream>
using namespace std;

struct node{
    int val;
    node *prev;
    node *next;

    node(int data){
        val=data;
        prev=next=nullptr;
    }
};
void printLL(node *head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

void remove_duplicates(node *head){
    node *temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->val == temp->next->val){
            node *dup = temp->next;          // duplicate node
            temp->next = dup->next;          // unlink duplicate
            if(dup->next) dup->next->prev=temp; // fix prev link
            delete dup;                      // free memory
        }
        else{
            temp = temp->next;  // move forward only if no duplicate
        }
    }
}
int main(){
    node *head=new node(1);
    head->next=new node(1);
    head->next->prev=head;
    head->next->next=new node(2);
    head->next->next->prev=head->next;
    head->next->next->next=new node(3);
    head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new node(3);
    head->next->next->next->next->prev=head->next->next->next;
    printLL(head);
    remove_duplicates(head);
    cout<<"\nRemoved duplicates \n";
    printLL(head);

    return 0;



}
