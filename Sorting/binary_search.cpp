#include<iostream>
using namespace std;
int main(){
    int arr[9]={9,12,23,45,56,88,89,90,100};//array need to be sorted 
    int size=9;
    int l=0;
    int r=size-1;
    int mid=0;
    int search_no=12;
    bool flag=false;
    while(l<r){
        mid=(l+r)/2;
        if(arr[mid]==search_no){
            cout<<"the value is at index "<<mid;
            flag=true;
            break;

        }
        else if(search_no>arr[mid]){
            l=mid+1;

        }
        else if(search_no<arr[mid]){
            r=mid-1;

        }
    }
    if(flag==false){
        cout<<"no do not exist.";
    }
    return 0;

}