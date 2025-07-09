#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr={1,0,0,4,0,6,7};
    int i=0,j=0;
    int n=arr.size();
    while (i < n) {
       
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}