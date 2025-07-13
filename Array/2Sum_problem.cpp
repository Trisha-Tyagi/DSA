#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr={2,3,5,0,3,4};
    int k=6;
    int n=arr.size();
    map<int,int> dic;
    for(int i=0;i<arr.size();i++){
        int target=k-arr[i];
        if(dic.find(target)!=dic.end()){
            cout<<"Yes"<<endl;
            cout<<i<<"and"<<dic[target]<<endl;
        }
        dic[arr[i]]=i;
    }
    
// using map data structure
    cout<<"Without map"<<endl;
    sort(arr.begin(),arr.end());
    int left=0,right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==k){
            cout<<"Yes"<<endl;
            cout<<left<<" and "<<right<<endl;
            left++;
        }
        else if(sum>k){
            right--;
        }
        else{
            left++;
        }

    }

    return 0;

}