#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1], arr[i][1]);
        }

    }
    return ans;
}
int main(){
    vector<vector<int>> arr={{1,12},{15,19},{6,7},{3,6},{8,10}};
    vector<vector<int>> result=merge(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
    return 0;


}