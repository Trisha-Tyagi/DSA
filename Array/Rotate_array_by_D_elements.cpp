#include<iostream>
#include<vector>
using namespace std;

void Reverse(vector<int> &arr,int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
        }
   
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    int k=2;
    int n=arr.size();
    Reverse(arr,n-k,n-1);
    Reverse(arr,0,n-k);
    Reverse(arr,0,n-1);

    for(int i:arr){
        cout<<i<<" ";
    }
    
    return 0;

}