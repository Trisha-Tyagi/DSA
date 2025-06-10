#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[9]={23,77,54,7,76,66,288,9,98};
    int size=8;
    int gap=size/2;
    while (gap>=1){
        cout<<gap<<endl;
        for(int i=0,j=i+gap;j<9;i++,j++){
            cout<<"i="<<i<<" and j="<<j<<endl;
            if(arr[i]>arr[j] ){
                swap(arr[i],arr[j]);
                if(i>=gap && arr[i]<arr[i-gap]){
                    swap(arr[i-gap],arr[i]);
                }
            }
            
        }
        gap=gap/2;
    }
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}