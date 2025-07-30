#include<iostream>
#include<string>
using namespace std;
string result(string s){
    int n=s.size();
    string ans="";
    int cnt=0;
    for(char i:s){
        if(i=='('){
            if(cnt) ans+='(';
            cnt++;
        }
        else{ cnt--;
        if(cnt) ans+=')';
    }
    }
    return ans;
}
int main(){
    string s="(())((()()))(()())";
    string ans=result(s);
    for(char i:ans){
        cout<<i;
    }
    return 0;
}