#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//finding left first smaller element
vector<int> left_small_element(vector<int> histogram){
    int n=histogram.size();
    vector<int> result(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && histogram[st.top()]>=histogram[i]){
            st.pop();
        }
        if(!st.empty()) result[i]=st.top();
        st.push(i);
    }
    return result;    
    

}
//finding right first smaller element
vector<int> right_small_element(vector<int> histogram){
    int n=histogram.size();
    vector<int> result(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && histogram[st.top()]>=histogram[i]){
            st.pop();
        }
        if(!st.empty()) result[i]=st.top();
        st.push(i);
    }
    return result;    
    

}


int main(){
    vector<int> histogram={1,2,4,3,5,6,1,2};
    vector<int> lse,rse;
    lse=left_small_element(histogram);
    rse=right_small_element(histogram);
    int area=0;
    for(int i=0;i<histogram.size();i++){
        int sec=rse[i]-lse[i]-1;
        int currarea=sec*histogram[i];
        area=max(area,currarea);
    }
    cout<<"Maximum Area of Rectangle in Histogram is: "<<area;
    return 0;
}
