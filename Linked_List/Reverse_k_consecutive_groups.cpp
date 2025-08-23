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
void reverse(node *head){
    node*prev=nullptr;
    node *next=nullptr;
    while(head!=nullptr){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
}
node * kthNode(node *temp,int k){
    k-=1;
    while(k>0 && temp!=nullptr){
        k--;
        temp=temp->next;

    }
    return temp;
}

node* reverse_groups(node *head,int  k){
    node *prevgroup=nullptr;
    node *temp=head;
    while(temp!=nullptr){
        node *kth=kthNode(temp,k);
        if(kth==nullptr){
            if(prevgroup){
                prevgroup->next=temp;
            }
            break;
        }
        node*nextnode=kth->next;
        kth->next=nullptr;
        reverse(temp);
        if(head==temp){
            head=kth;
            
        }
        else{
            prevgroup->next=kth;
            
        }
        prevgroup=temp;
        temp=nextnode;
        

    }
    return head;

}

void printLL(node *head){
    while(head!=nullptr){
        cout<<head->data<<endl;
        head=head->next;
    }
}
int main(){
    node *newnode = new node(5);
    node *head=newnode;
    node *temp=head;
    temp->next=new node(6);
    temp=temp->next;
    temp->next=new node(7);
    temp=temp->next;
    temp->next=new node(9);
    temp=temp->next;
    temp->next=new node(8);
    temp=temp->next;
    temp->next=new node(0);
    temp=temp->next;
    temp->next=new node(10);
    temp=temp->next;
    temp->next=new node(18);
    
    
    cout<<"Before:\n";
    printLL(head);
    head=reverse_groups(head,3);
    cout<<"After:\n";
    printLL(head);
    

    return 0;
}
