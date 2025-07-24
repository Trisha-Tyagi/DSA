#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec={1,3,3,4,5,6,7};
    int n=vec.size();
    
    long long Sn=n*(n+1)/2;
    long long S2n=(n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i:vec){
        S2+=(long long)i*(long long)i;
        S+=i;
    }
    long long val1=Sn-S;
    long long val2=S2n-S2;
    val2=val2/val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    cout<<"Repeating Number : "<<y<<endl;
    cout<<"Missing Number : "<<x;
    return 0;

}