#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;

    node(int val): data(val),prev(nullptr),next(nullptr){}
};

vector<vector<int>> Sum_pair(node *head,int k){
    node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    vector<vector<int>> pairs;
    node *first=head,*second=temp;
    while(first!=second){
        int sum=0;
        sum+=first->data;
        sum+=second->data;
        if(sum>k){
            second=second->prev;
        }else if(sum<k){
            first=first->next;

        }
        else{
            pairs.push_back({first->data,second->data});
            second=second->prev;
        }

    }
    return pairs;

}
int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->prev = head;
    head->next->next = new node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new node(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new node(6);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new node(8);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new node(9);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->next = new node(11);
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next = new node(13);
    head->next->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next->next = new node(15);
    head->next->next->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next->next->next;

    int k=10;
    vector<vector<int>> result=Sum_pair(head,k);
    cout<<"PAIRS WITH GIVEN SUM ARE: \n";
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}
