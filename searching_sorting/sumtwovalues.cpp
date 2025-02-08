#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int a[n];
    pair<int, int> original[n]; // To store the value and original index.

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        original[i] = {a[i], i + 1}; // Store 1-based index.
    }

    // Sort based on values while keeping track of original indices.
    sort(original, original + n);

    int i = 0, j = n - 1;
    bool found = false;

    while (i < j) {
        int sum = original[i].first + original[j].first;

        if (sum == x) {
            // Output 1-based indices of the pair.
            cout << original[i].second << " " << original[j].second << endl;
            found = true;
            break;
        }

        if (sum < x) {
            i++;
        } else {
            j--;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
