#include<iostream>
#include<vector>
using namespace  std;
int main(){
    vector<int> vec={1,-4,3,5,-6,7,8,0,-3,9};
    int pref=0,suff=0;
    int n=vec.size();
    int max_prod=INT16_MIN;
    for(int i=0;i<vec.size();i++){
        if(pref==0) pref=1;
        if(suff==0) suff=1;
        pref*=vec[i];
        suff*=vec[n-i-1];
        max_prod=max(max_prod,max(pref,suff));
    }
    cout<<max_prod;
    return 0;
}