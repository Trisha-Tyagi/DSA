#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set<vector<int>> Sum(vector<int> arr, int k)
{
    set<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        set<int> set;
        int target1 = k - arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            int target = target1 - arr[j];
            if (set.find(target) != set.end())
            {
                vector<int> m = {arr[i], arr[j], target};
                sort(m.begin(), m.end()); // necesssary to sort before inserting so that the different permutation do not occur in set
                result.insert(m);
            }
            set.insert(arr[j]);
        }
        set.insert(arr[i]);
    }
    return result;
}
int main()
{
    vector<int> arr = {1, 10, -1, 0, -3, 5,-2,7,9,-10,-4,-3,-2};
    int k = 0;
    set<vector<int>> ans = Sum(arr, k);
    cout<<" 3 Elements that sum up to give sum k\n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}