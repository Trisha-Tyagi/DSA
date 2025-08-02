#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool Anagram(string s1,string s2){
    vector<int> result(26,0);
    int n=s1.size();
    for(int i=0;i<n;i++){
        result[s1[i]-'0']++;
    }
    for(int i=0;i<n;i++){
        result[s2[i]-'0']--;
    }
    for(int i=0;i<n;i++){
        if(result[i]!=0) return false;
    }
    return true;

}


int main(){
    string s1="CATFDP";
    string s2="ACTPDF";
    bool result =Anagram(s1,s2);
    if(result){
        cout<<"True,Strings are Anagram.";

    }
    else{
        cout<<"False,Strings are  not Anagram.";
    }
    return 0;
}