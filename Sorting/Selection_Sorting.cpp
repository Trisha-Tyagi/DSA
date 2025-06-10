#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int size;
    vector<int> age;
    cout<<"Enter the size of array: ";
    cin>>size;
    age.resize(size);
    cout<<"Enter the array you want to sort: ";
    for(int i=0;i<size;i++){
        cin>>age[i];
    }

    // for(int i=0;i<size;i++){
    //     int min_index=i;
    //     for(int j=i+1;j<size;j++){
    //         if(age[j]<age[min_index]){
    //             min_index=j;
    //             // swap(age[i],age[j]);//wrong way//as it will replace each element without complete loop completion

    //         }
            
    //     }
    //     if(min_index != i){
    //         swap(age[min_index],age[i]);
    //         }

    // }
    



    for(int i=0;i<size-1;i++){
        int no =INT8_MIN;
        for(int j=i;j<size;j++){
            if(age[j]<no){
                no=age[j];
            }

        }
        swap(age[i],no);
    
}

    for(int i=0;i<size;i++){
        cout<<age[i]<<endl;
    }
    
    return 0;
}