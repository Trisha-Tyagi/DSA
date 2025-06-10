#include <iostream>
#define size 5
using namespace std;
int stack[size];
int top=-1;

void push(int data){
    
    top++;
    stack[top]=data;
}
    
void pop(){
    cout<<stack[top];
    top--;
}

void display(){
    for(int i =top;i>=-1;i--){
        cout<<stack[i];
    }
}
int main(){
    push(4);
    push(5);
    display();
    return 0;
}