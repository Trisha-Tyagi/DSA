#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int> arr={2,3,4,0,6,-7,1,2,1};
    int XOR=4;
    map<int,int> dic;
    int n=arr.size();
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        sum^=arr[i];
        int target=sum^XOR;
        if(sum==XOR){
            count++;
        }
        if(dic.find(target)!=dic.end()){
            count+=dic[target];
        }
        dic[sum]++;


    }
    cout<<count;

}