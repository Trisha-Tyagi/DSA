#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=6;
    
    vector<vector<int>> result(n);
    for(int i=0;i<n;i++){
        result[i].push_back(1);
        int sum=1;
        for(int  j=0;j<=i;j++){
            sum*=(i-j);
            sum/=(j+1);
            result[i].push_back(sum);
        }

    }
    for(int i=0;i<n;i++){
        
        for(int  j=0;j<=i;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;

    }
    return 0;
    
}
