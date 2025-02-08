#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Map to store the sum of pairs and their indices
    unordered_map<ll, pair<int, int>> sumPairs;

    // Iterate over the array
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll requiredSum = x - (a[i] + a[j]);

            // Check if requiredSum exists in map
            if (sumPairs.find(requiredSum) != sumPairs.end()) {
                auto [p1, p2] = sumPairs[requiredSum];

                // Ensure all indices are distinct
                if (p1 != i && p1 != j && p2 != i && p2 != j) {
                    cout << p1 + 1 << " " << p2 + 1 << " " << i + 1 << " " << j + 1;
                    return 0;
                }
            }
        }

        // Store pairs (i, j) in hash map
        for (ll k = 0; k < i; k++) {
            sumPairs[a[k] + a[i]] = {k, i};
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
