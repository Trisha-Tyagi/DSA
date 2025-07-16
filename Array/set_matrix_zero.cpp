#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> set_zeroes(vector<vector<int>> &arr){
    int n=arr.size();
    int m=arr[0].size();
    vector<int> col(m,0);
    vector<int> row(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
    {
        if(row[i] || col[j]){
            arr[i][j]=0;}
        }
    }
    return arr;

}


int main(){
    vector<vector<int>> arr={{2,3,0},{6,33,54},{0,21,3}};
    vector<vector<int>> result=set_zeroes(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }


    return 0;
    }
