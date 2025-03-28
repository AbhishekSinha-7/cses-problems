#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long count = 0;
    
    // Count powers of 5
    for(long long i = 5; i <= n; i *= 5) {
        count += n/i;
    }
    
    cout << count << endl;
    
    return 0;
}