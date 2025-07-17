#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {3, 4, 5, 6}, {9, 0, 8, 7}};
    vector<int> ans;
    int n = mat.size();
    int m = mat[0].size();
    int top = 0, right = m - 1, bottom = n - 1, left = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);

        top++;

        // For moving top to bottom.
        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);

        right--;

        // For moving right to left.
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);

            bottom--;
        }

        // For moving bottom to top.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);

            left++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;
}