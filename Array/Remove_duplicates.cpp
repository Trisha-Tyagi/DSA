#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 7};
    int n = arr.size();
    
    int i,j=0;
    for(i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            arr[j++]=arr[i];
            
        }

    }
    
    arr[j++]=arr[n-1];
    
    cout<<"No of Unique Element: "<<j<<endl;
    for (int k = 0; k < j; k++)
    {
        cout << arr[k] << " ";
    }
    return 0;
}