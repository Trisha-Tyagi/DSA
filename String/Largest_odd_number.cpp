#include <iostream>
#include <string>
using namespace std;
// Optimal Approach
// TC:O(n)
// SC:O(n)
string largestOddNumber(string num) {
    int n = num.size();
    for (int i = n - 1; i >= 0; i--) {
        int no = num[i] - '0';  // Convert character to integer
        if (no % 2 != 0) {
            return num.substr(0, i + 1);  // Return prefix ending at the last odd digit
        }
    }
    return "";  // No odd digit found
}


int main() {
    
    string input="2345728";

    string result = largestOddNumber(input);
    if (result.empty()) {
        cout << "No odd-ending prefix found." << endl;
    } else {
        cout << "Largest odd-ending prefix: " << result << endl;
    }

    return 0;
}
