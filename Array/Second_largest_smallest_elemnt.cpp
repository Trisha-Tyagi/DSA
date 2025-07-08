#include<iostream>
#include<vector>
using namespace std;



int main(){

    vector<int> arr={1,2,4,7,7,5};
    int n=arr.size();
    int smallest=INT16_MAX,largest=INT16_MIN;
    int sec_largest=INT16_MIN,sec_smallest=INT16_MAX;

    ////////////////////////////////////////////// Better Approach///////////////////////////////////////////////


    // if(n<2) cout<<"Largest: "<<-1<<endl<<"Smallest: "<<-1;
    // for(int i=0;i<n;i++){
    //     smallest=min(smallest,arr[i]);
    //     largest=max(largest,arr[i]);
    // } 
    
    // for(int i=0;i<n;i++){
    //     if(arr[i]<largest && arr[i]>sec_largest){
    //         sec_largest=arr[i];
    //     }
    //     if(arr[i]>smallest && arr[i]<sec_smallest){
    //         sec_smallest=arr[i];
    //     }


    // }
    // cout<<"Second Largest element: "<<sec_largest<<endl;
    // cout<<"Second Smallest element: "<<sec_smallest;
    

    ////////////////////////////////////////////////// Optimal approach//////////////////////////////////////////////////


    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            sec_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>sec_largest){
            sec_largest=arr[i];

        }
        if(arr[i]<smallest){
            sec_smallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<sec_smallest){
            sec_smallest=arr[i];

        }
    }
    cout<<"Second Largest element: "<<sec_largest<<endl;
    cout<<"second Smallest element: "<<sec_smallest;


    return 0;
}