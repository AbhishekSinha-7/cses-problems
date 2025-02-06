#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int a, b;
        cin >> a >> b;
        
        // Check three conditions:
        // 1. Sum should be divisible by 3 (since we remove 3 coins in each step)
        // 2. Larger pile should be at most 2 times the smaller pile
        // 3. Neither pile should be negative
        
        if((a + b) % 3 == 0 && 
           max(a,b) <= 2*min(a, b) && 
           min(a, b) >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}