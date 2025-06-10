#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> age; 
    int size;
    cout<<"Enter the size of array:"<<" ";   
    cin>>size;
    age.resize(size);
    cout<<endl;
    cout<<"Enter the array you want to get sorted"<<" ";
    for(int i=0;i<size;i++){
        cin>>age[i];//if working with indicies in vector you need to resize the vector with size---age.resize(size)
    //else use pushback
    }
    
    for(int k=0;k<size-1;k++){
        bool flag=false;
        for(int j=0;j<size-k-1;j++){
            if(age[j]>age[j+1]){
                int temp=age[j];
                age[j]=age[j+1];
                age[j+1]=temp;
                flag=true;
            }
        if(flag==false){
            break;
        }
        }
    }
    for(int l=0;l<size;l++){
        cout<<age[l]<<endl;
    }
    
return 0;
}