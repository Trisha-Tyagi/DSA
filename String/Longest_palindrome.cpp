#include<iostream>
#include<string>
using namespace std;

// TC:O(n^2)
// SC:O(1)
string palindrome(string s,int left,int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return s.substr(left+1,right-left-1);
}
int main(){
    string s="ababbabc";
    int n=s.size();
    string result="";
    for(int i=0;i<n-1;i++){
        string ans1=palindrome(s,i,i);
        string ans2=palindrome(s,i,i+1);
        if(ans1.size()>result.size()) result=ans1;
        if(ans2.size()>result.size()) result=ans2;
    }
    
    cout<<result;
    return 0;
}