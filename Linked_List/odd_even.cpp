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

Node* even_odd(Node *head){
    Node *even=nullptr, *even_head=nullptr;
    Node *odd=nullptr, *odd_head=nullptr;

    while(head!=nullptr){
        Node *nextNode = head->next; // store next
        head->next=nullptr;          // break old connection

        if(head->data % 2 == 0){ // even
            if(even){
                even->next = head;
                even = head;
            } else {
                even = even_head = head;
            }
        } else { // odd
            if(odd){
                odd->next = head;
                odd = head;
            } else {
                odd = odd_head = head;
            }
        }

        head = nextNode; // move ahead
    }

    if(!even_head) return odd_head;   // no evens
    if(!odd_head) return even_head;   // no odds

    even->next = odd_head; // join
    return even_head;
}

void printLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node*head=new Node(9);
    head->next=new Node(8);
    head->next->next=new Node(10);
    head->next->next->next=new Node(8);
    head->next->next->next->next=new Node(9);

    head=even_odd(head);
    printLL(head);

    return 0;
}
