#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findMinDiff(int idx, ll group1, ll group2, vector<ll>& apples) {
    // Base case: When we've processed all apples
    if (idx == apples.size()) {
        return abs(group1 - group2);
    }
    
    // Include current apple in first group
    ll diff1 = findMinDiff(idx + 1, group1 + apples[idx], group2, apples);
    
    // Include current apple in second group
    ll diff2 = findMinDiff(idx + 1, group1, group2 + apples[idx], apples);
    
    // Return the minimum difference
    return min(diff1, diff2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> apples(n);
    for(int i = 0; i < n; i++) {
        cin >> apples[i];
    }
    
    cout << findMinDiff(0, 0, 0, apples) << "\n";
    
    return 0;
}