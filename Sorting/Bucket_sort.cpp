//this sort is mainly for decimal no in a described range mainly 0-1
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
void bucket_sort(vector<double> &vec ,int size){
    vector<vector<double>> buckets(size);
    for(int i=0;i<size;i++){
        
        int bucket_index=static_cast<int>(floor(size*vec[i]));
        buckets[bucket_index].push_back(vec[i]);
    }
    for(int i=0;i<size;i++){
        sort(buckets[i].begin(), buckets[i].end());
    }
     int index = 0;
    for (int i = 0; i < size; i++) {
        sort(buckets[i].begin(), buckets[i].end()); // Sort individual buckets
        for (double value : buckets[i]) {
            vec[index++] = value;
        }
    }
}
int main(){
    vector<double> vec={0.34,0.32,0.6,0.2,0.3};
    int size=vec.size();
    // cout<<size;
    bucket_sort(vec,size);
    // for(double i:vec){
        
    //     cout<<i<<",";
    // }/
    for(int i=0;i<size;i++){
        if(i==size-1){
            cout<<vec[i];
        }
        else{
            cout<<vec[i]<<",";
        }
    }
    return 0;

}