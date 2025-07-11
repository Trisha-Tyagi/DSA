#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 2, 4, 3, 6, 5, 6, 4, 3};
    int k = 7;

    int n = arr.size();
    long long sum = 0;
    int max_len = 0;
    int j = 0, i = 1;

    sum += arr[j];
    while (i < n)
    {

        while (j < i && sum > k)
        {

            sum -= arr[j];
            j++;
        }
        if (sum == k)
        {
            max_len = max(max_len, i - j + 1);
            i++;
        }

        i++;

        if (i < n)
            sum += arr[i];
    }
    cout << max_len;
    return 0;
}