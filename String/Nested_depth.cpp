#include<iostream>
#include<string>
using namespace std;

// TC:O(n)
// SC:O(1)
int nested_depth(string s){
    int nested_depth=0;
    int count=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(') count++;
        else count--;
        nested_depth=max(count,nested_depth);

    }
    return nested_depth;
}


int main(){
    string s="((())(())(())()(((()))))";
    int ans=nested_depth(s);
    cout<<"Nested Depth: "<<ans;
    return 0;
}
