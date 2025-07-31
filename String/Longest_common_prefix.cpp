#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// Time Complexity:O(n.k)
// Space Complexity:O(1)
// Optimal Approach
string Longest_prefix(vector<string> arr){
    string prefix=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=0;
        while(j<prefix.length() && j<arr[i].length() && prefix[j]==arr[i][j]){
            j++;
        }
        prefix=arr[i].substr(0,j);
    }
    return prefix;
}
// Better approach
// TC:O(k.nlogn)
// SC:O(1)
string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        int n=min(first.length(),last.length());
        string ans="";
        for(int i=0;i<n;i++){
            if(first[i]!=last[i]) return ans;
            ans+=first[i];


        }
        return ans;
    }

int main(){
    vector<string> arr1={"flow","float","flower","floo"};
    vector<string> arr2={"interspace", "interstellar", "internet", "interact"};
    string ans1=Longest_prefix(arr1);
    string ans2=longestCommonPrefix(arr2);
    cout<<"Optimal Approach:"<<endl;
    for(char i:ans1){
        cout<<i;
        }
    cout<<"\n\nBetter Approach:"<<endl;
    for(char i:ans2){
    cout<<i;
    }
    return 0;
}