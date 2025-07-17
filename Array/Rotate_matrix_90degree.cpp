#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // vector<vector<int>> arr={{1,2,3,4},{6,7,8,9},{11,12,34,21}};
    // int n=arr.size();
    // int m=arr[0].size();

    //////////////////////////// Brute force//////////////////////////

    // vector<vector<int>> result(m, vector<int>(n, 0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         result[j][n-i-1]=arr[i][j];
    //     }
    // }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //////////////////////////// Optimal////////////////////////////

    vector<vector<int>> arr={{1,2,3,4},{6,7,8,9},{11,12,34,21},{0,5,9,8}};
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            
            swap(arr[i][j],arr[j][i]);
            

        }
    }
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}