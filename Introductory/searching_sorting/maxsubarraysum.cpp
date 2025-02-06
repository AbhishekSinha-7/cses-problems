#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long  a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long  max_sum = INT_MIN; // Initialize to smallest possible integer
    long long  current_sum = 0;   // Tracks the sum of the current subarray

    for (int i = 0; i < n; i++) {
        current_sum = max(a[i], current_sum + a[i]); // Include current element or start new subarray
        max_sum = max(max_sum, current_sum);         // Update maximum sum
    }

    cout << max_sum << endl;

    return 0;
}
