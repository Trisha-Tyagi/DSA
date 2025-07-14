#include<iostream>
#include<vector>
using namespace std;
int largest_sum(vector<int> arr){
    int sum=0;
    int max_sum=INT16_MIN;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        max_sum=max(max_sum,sum);
        
        if(sum<0){
            sum=0;
        }
        

    }
    return max_sum;
}
int main(){
    vector<int> arr={ -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sum=largest_sum(arr);
    cout<<sum;
    return 0;
}