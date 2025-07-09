#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<int> arr={1,2,3,2,4,3,6,5,6,4,3};
    int k=7;
    map<long long,int> Sumindex;
    int n=arr.size();
    long long sum=0;
    int max_len=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        Sumindex[sum]=i;
        int len=0;
        if(sum==k){
            max_len=i;
        }
        long long rem=sum-k;
        if(Sumindex.find(rem)!=Sumindex.end()){
            len=i-Sumindex[rem];
            max_len=max(len,max_len);
        }
        if (Sumindex.find(sum) == Sumindex.end()) {
           Sumindex[sum] = i;
        }


    }
    
    cout<<max_len;
}