#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int lb,int mid,int ub){
    int left=lb;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=ub){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=ub){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=lb;i<=ub;i++){
        arr[i]=temp[i-lb];
    }

}


void mergesort(vector<int>& arr,int lb,int ub){
    if(lb>=ub) return ;
    int mid=(lb+ub)/2;
    mergesort(arr,lb,mid);
    mergesort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
    

}


int main(){
    vector<int> arr={3,23,45,63,13,-1,10,2,-45,-2,9,60};
    int n=arr.size();
    mergesort(arr,0,n-1);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
