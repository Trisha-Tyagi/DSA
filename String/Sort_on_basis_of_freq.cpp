#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
// TC:O(n+klogk)==O(n)
// SC:O(n)
// Uppercase andd lowercase are treated different characters
using namespace std;

// Comaparator function
    bool compare(pair<char,int> a,pair<char,int> b){
        return a.second>b.second;
    }
string frequencySort(string s) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Move (char, frequency) into a vector
    vector<pair<char, int>> freqVec(freq.begin(), freq.end());

    // Step 3: Sort vector by frequency in descending order
    sort(freqVec.begin(), freqVec.end(), compare);

    // Step 4: Build the result string
    string result = "";
    for (auto& p : freqVec) {
        result += string(p.second, p.first); // repeat char 'p.first' 'p.second' times
    }

    return result;
}

int main() {
    string s = "Ssakkkishtyagisas";
    string sorted = frequencySort(s);
    cout << sorted << endl; // Output: eetr or ttee
    return 0;
}
