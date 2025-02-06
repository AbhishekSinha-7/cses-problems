#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<string> v;
    // Sort first to get lexicographically smallest permutation
    sort(s.begin(), s.end());
    
    // Keep generating next permutation until we get back to first one
    do {
        v.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    
    cout << v.size() << "\n";
    for(const string& x : v) {
        cout << x << "\n";
    }
    
    return 0;
}