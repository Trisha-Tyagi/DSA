#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int stocks(vector<int> arr){
    int max_pro=0;
    int n=arr.size();
    int min_element=arr[0];
    for(int j=1;j<n;j++){
        
        if(arr[j]>min_element){
            int prof=arr[j]-min_element;
            max_pro=max(max_pro,prof);
        }
        else if(arr[j]<min_element){
            min_element=arr[j];

        }
        
    }
    if(max_pro==0) return -1;
    else return max_pro;
}



int main(){
    vector<int> arr={2,4,5,7,8,9,10,23,45};
    reverse(arr.begin(),arr.end());
    int profit=stocks(arr);
    cout<<profit;
    return 0;
    
}