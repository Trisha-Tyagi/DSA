#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={1,2,3,5,6,7,8};
    int XOR=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        XOR^=arr[i];
    }
    for(int i=1;i<n+2;i++){
        XOR^=i;
    }
    cout<<XOR;
}
//XOR method is better than summation because if the length of array will be more(like 10^5) then the storage of sum will can be an issue.