// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;
int quicksort(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while (start<end){
        while(pivot>=a[start]){
            start++;
            
        }
        
        while(pivot<a[end]){
            end--;
        }
        if (start<end){
            swap(a[start],a[end]);
        }
    }
    swap(a[lb],a[end]);
    return end;
}
void Quicksort(int a[],int lb,int ub){
    if(lb<ub){
    int loc;
    loc = quicksort(a,lb,ub);
    Quicksort(a,lb,loc-1);
    Quicksort(a,loc+1,ub);
    }
}
int main(){
    int a[]={1,3,22,4,11,5};
    int size=sizeof(a)/sizeof(a[0]);
    Quicksort(a,0,size-1);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}

