#include <iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr,int lb,int mid,int ub){
    int left=lb;
    int right=mid+1;
    vector<int> temp;
    int cnt=0;
    while(left<=mid && right<=ub){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
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
    return cnt;

}


int mergesort(vector<int>& arr,int lb,int ub){
    int cnt=0;
    if(lb>=ub) return cnt;
    int mid=(lb+ub)/2;
    
    cnt+=mergesort(arr,lb,mid);
    cnt+=mergesort(arr,mid+1,ub);
    cnt+=merge(arr,lb,mid,ub);
    return cnt;
    

}


int main(){
    vector<int> arr={5,3,2,4,1};
    int n=arr.size();
    int count=mergesort(arr,0,n-1);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\nNo of Inversions are : "<<count;
    return 0;
}
