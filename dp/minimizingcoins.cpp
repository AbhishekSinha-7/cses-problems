#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // DP table: `dp[i]` stores the minimum number of coins needed to form sum `i`
    vector<int> dp(x + 1, INF);
    dp[0] = 0; // Base case: No coins needed to form sum `0`

    // Iterating over all coins
    for (int coin : v) {
        for (int j = coin; j <= x; j++) {
            if (dp[j - coin] != INF) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << endl;
    return 0;
}
