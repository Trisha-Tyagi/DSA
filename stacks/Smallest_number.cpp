#include<iostream> 
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> swm(vector<int> arr,int k){
    stack<int> st;
    vector<int> result;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top()>arr[i] && k>0){
            st.pop();
            k--;
        }
        st.push(arr[i]);
        
    }
    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;

}
int main(){
    vector<int> arr={5,3,0,2,1,6,9};
    int k=3;
    vector<int> result=swm(arr,k);
    cout<<"Smallest number is: ";
    for(int i:result){
        cout<<i<<" ";
    }
}
