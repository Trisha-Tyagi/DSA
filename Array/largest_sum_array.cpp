#include<iostream>
#include<vector>
using namespace std;
vector<int> largest_sum(vector<int> arr){
    int sum=0;
    int start=0,end=arr.size();
    int max_sum=INT16_MIN;
    for(int i=0;i<arr.size();i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(sum>max_sum){
            max_sum=max(sum,max_sum);
            end=i+1;

        }
        max_sum=max(max_sum,sum);
        
        if(sum<0){
            sum=0;
            
        }
        

    }
    return {max_sum,start,end};
}
int main(){
    vector<int> arr={ -2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> sum=largest_sum(arr);
    cout<<sum[0]<<endl;
    cout<<sum[1]<<" "<<sum[2]<<endl;
    for(int i=sum[1];i<sum[2];i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}