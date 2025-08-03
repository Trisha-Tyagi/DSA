#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int Roman_to_int(string s){
    unordered_map<char,int> hint={{'I',1},{'V',5},{'L',50},{'C',100},{'M',1000},{'D',500},{'X',10}};
    int n=s.size();
    int ans = 0;
    int prev = 0;

    for (int i = n - 1; i >= 0; i--) {
        int curr = hint[s[i]];
        if (curr < prev) {
            ans -= curr;
        } else {
            ans += curr;
        }
        prev = curr;
    }
    return ans;
}


int main(){
    string Roman="LMX";
    int integer=Roman_to_int(Roman);
    cout<<"Integer form of "<<Roman<<":\n";
    cout<<integer;
    return 0;

}