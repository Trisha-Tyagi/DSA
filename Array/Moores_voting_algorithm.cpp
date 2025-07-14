#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> arr={1,2,2,3,1,3,3,2,3};
    int N=arr.size();
    int k=N/2;
    int count=0,element=0;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            element=arr[i];
        }
        if(arr[i]==element) count++;
        else count--;

    }
    int freq = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] == element) freq++;
    }
    if(freq>k) cout<<element;
    else cout<<-1;
}