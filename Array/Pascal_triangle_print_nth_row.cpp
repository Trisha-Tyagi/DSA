#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=6;
    vector<int> result;
    
        result.push_back(1);
        int sum=1;
        for(int  j=0;j<=n;j++){
            sum*=(n-j);
            sum/=(j+1);
            result.push_back(sum);
        }

    
    
        for(int  j=0;j<=n;j++){
            cout<<result[j]<<" ";
        }
        cout<<endl;

    
    return 0;
    
}