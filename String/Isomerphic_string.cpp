#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// Time complexity:O(n)
// Space Complexity:O(1)
bool isomorphic(string s1,string s2){
    unordered_map<char,char> map1,map2;
    int n=s1.size();
    for(int i=0;i<n;i++){
        if(map1[s1[i]] && map1[s1[i]]!=s2[i]) return false;//should use map.count(s[i])🤔
        if(map2[s2[i]] && map2[s2[i]]!=s1[i]) return false;

        map1[s1[i]]=s2[i];
        map2[s2[i]]=s1[i];

    }
    return true;
}



int main(){
    string s1="pape";
    string s2="tttt";
    bool result=isomorphic(s1,s2);
    cout<<result;
    return 0;
}