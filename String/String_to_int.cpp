#include<iostream>
#include<string>
using namespace std;
// TC:O(n)
// SC:O(1)
int str_to_int(string s){
    
    
        int n=s.size();
    int sign=1;
    int i=0;
    int ans=0;
    while(i<n && s[i]== ' ') i++;
    if(i==n) return ans;
    if(s[i]=='-'){ sign=-1;
        i++;}
    else if(s[i]=='+'){
        sign=1;
        i++;
    }
    while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow BEFORE it happens
            if (ans > (INT64_MAX - digit) / 10) {
                return sign == 1 ? INT64_MAX : INT64_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }
    if(sign==-1) return sign*ans;
    return ans;
    
    }
int main(){
    string s="   -567ab";
    int no=str_to_int(s);
    cout<<"The number extracted is: "<<no;
    return 0;
}