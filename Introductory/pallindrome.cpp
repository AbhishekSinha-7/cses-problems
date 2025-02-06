#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    // Count frequencies
    for(char c : s) {
        freq[c]++;
    }
    
    // Check if palindrome is possible
    int oddCount = 0;
    char oddChar;
    for(auto &p : freq) {
        if(p.second % 2 != 0) {
            oddCount++;
            oddChar = p.first;
        }
    }
    
    // If more than one character has odd frequency, no solution
    if(oddCount > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    // Build palindrome
    string result = "";
    
    // Add first half
    for(auto &p : freq) {
        string half = "";
        for(int i = 0; i < p.second / 2; i++) {
            half += p.first;
        }
        
        result += half;
    }
    
    // Add middle character (if exists)
    if(oddCount == 1) {
        result += oddChar;
    }
    
    // Add second half
    for(int i = result.length() - 1 - oddCount; i >= 0; i--) {
        result += result[i];
    }
    
    cout << result;
    return 0;
}