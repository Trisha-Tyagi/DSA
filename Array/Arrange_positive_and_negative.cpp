#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={1,-2,-3,4,5,-9,0};
    int n=arr.size();
    vector<int> result(n,0);
    int pos=0,neg=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            result[neg]=arr[i];
            neg+=2;
        }
        if(arr[i]>0){
            result[pos]=arr[i];
            pos+=2;
        }
    }
    cout<<"Array after rearranging is \n";
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}