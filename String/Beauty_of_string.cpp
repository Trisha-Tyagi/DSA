#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
int main(){
    string s = "aabcaacc";
    int beauty = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        unordered_map<char,int> dic;
        for (int j = i; j < n; ++j) {
            dic[s[j]]++;
            int mx = 0;
            int mn = INT_MAX;
            for (auto &p : dic) {
                mx = max(mx, p.second);
                mn = min(mn, p.second);
            }
            beauty += (mx - mn);
        }
    }
    cout<<"Beauty :"<<beauty;
    return 0;
}