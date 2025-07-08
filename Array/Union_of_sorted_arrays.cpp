#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 3, 4, 6, 8, 9};
    vector<int> result;
    int n = arr1.size();
    int m = arr2.size();

    int i = 0, j = 0;
    while (i < n && j < m)
    {

        if (arr1[i] <= arr2[j])
        {
            if (result.empty() || result[result.size() - 1] != arr1[i] )
            {
                result.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (result.empty() || result[result.size() - 1] != arr2[j]  )
            {
                result.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (j < m)
    {
        if (result[result.size() - 1] != arr2[j])
        {
            result.push_back(arr2[j]);
        }
        j++;
    }

    while (i < n)
    {
        if (result[result.size() - 1] != arr1[i])
        {
            result.push_back(arr1[i]);
        }
        i++;
    }

    for (int k : result)
    {
        cout << k << " ";
    }

    return 0;
}
