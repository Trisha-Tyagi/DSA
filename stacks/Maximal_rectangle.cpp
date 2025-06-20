#include <bits/stdc++.h>
using namespace std;


//finding left smaller elemnt for array
vector<int> left_smaller_element(vector<int> arr){
    vector<int> result(arr.size(),-1);
    stack<int> st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();

        }
        if(!st.empty()) result[i]=st.top();
        st.push(i);
    }
    return result;
}

//finding right smaller element for the array
vector<int> right_smaller_element(vector<int> arr){
    int n=arr.size();
    vector<int> result(arr.size(),n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();

        }
        if(!st.empty()) result[i]=st.top();
        st.push(i);
    }
    return result;
}

//Calculating maximum area of each row histogram
int max_area(vector<int> arr){
    
    
        int area=0;
        vector<int> lse=left_smaller_element(arr);
        vector<int> rse=right_smaller_element(arr);
        for(int j=0;j<arr.size();j++){
            int currarea=(rse[j]-lse[j]-1)*arr[j];
            area=max(area,currarea);
        }
    return area;
}


int main(){
    vector<vector<int>> matrix={{1,1,1,1},{1,1,1,1},{1,0,1,1},{1,1,1,0},{0,1,1,1}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    int area=0;
    vector<vector<int>> spare(rows, vector<int>(cols, 0));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0) spare[i][j]=0;
            else if(i>0 && matrix[i][j]!=0){
                spare[i][j]=spare[i-1][j]+1;
            }
            else spare[i][j]=1;
        }
    }

    for(int i=0;i<rows;i++){
        int currarea=max_area(spare[i]);
        area=max(currarea,area);

    }
    cout<<"Maximum Rectangle with 1's: "<<area;
    
    return 0;
}