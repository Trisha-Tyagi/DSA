#include<iostream>
#include<vector>
using namespace std;

// int main() {
//     vector<int> age;
//     int size;
    
//     cout << "Enter the size of array: ";
//     cin >> size;
    
//     age.resize(size);
    
//     cout << "Enter the array you want to sort: ";
//     for(int i = 0; i < size; i++) {
//         cin >> age[i];
//     }
    
//     for(int i = 1; i < size; i++) {
//         int temp = age[i];
//         int j = i - 1;
        
//         // Move elements that are greater than temp to one position ahead of their current position
//         while(j >= 0 && age[j] > temp) {
//             age[j + 1] = age[j];
//             j--;
//         }
        
//         // Place temp in its correct position
//         age[j + 1] = temp;
//     }
    
//     cout << "Sorted array:" << endl;
//     for(int i = 0; i < size; i++) {
//         cout << age[i] << endl;
//     }
    
//     return 0;
// }

int main(){
    int size;
    cout<<"Enter the size of array";
    cin>>size;
    vector<int> age(size);
    for(int i=0;i< size;i++){
        cout<<"enter "<<i<<"element: ";
        cin>>age[i];
    }
     
    int temp=0;
    for (int i=1;i<age.size();i++){
        temp=age[i];
        for (int j =i-1;j>=0;j--){
            if(age[j]>temp){
                age[j+1]=age[j];
                if(j==0){
                    age[j]=temp;
                }
            }
            else{
                age[j+1]=temp;
                break;
            }
        }
    }

    for (int i=0;i<size;i++){
        cout<<age[i]<<" ";
    }

}
