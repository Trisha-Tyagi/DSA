#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node* reverse(Node *head){
    Node *prev=nullptr, *next=nullptr;
    Node *temp=head;
    while(temp!=nullptr){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}

Node *middle(Node *head){
    Node*slow=head,*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void printLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool ispalindrome(Node *head){
    if(!head || !head->next) return true;
    Node *mid=middle(head);
    Node *second = reverse(mid);
    Node *first=head;
    Node *tempSecond=second;
    while(tempSecond!=nullptr){
        if(first->data!=tempSecond->data)
            return false;
        first=first->next;
        tempSecond=tempSecond->next;
    }
    return true;
}

int main(){
    Node*head=new Node(9);
    head->next=new Node(8);
    head->next->next=new Node(10);
    head->next->next->next=new Node(8);
    head->next->next->next->next=new Node(9);

    printLL(head);

    bool result=ispalindrome(head);
    cout<<"Linked List is Palindrome: "<< (result ? "Yes" : "No") <<endl;

    return 0;
}
