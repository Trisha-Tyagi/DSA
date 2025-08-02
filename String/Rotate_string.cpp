#include<iostream>
#include<string>
using namespace std;
bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;
        for(int i=n-1;i>=0;i--){
            string a=goal.substr(i,n);
            string b=goal.substr(0,i);
            string result=a+b;
            if(result==s){
                return true;
            }

        }
        return false;
        
    }
int main(){
    string s1="abcde";
    string s2="cdeab";
    bool result=rotateString(s1,s2);
    if(result) cout<<"True";
    else cout<<"False";
}