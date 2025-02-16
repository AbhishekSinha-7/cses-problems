#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool ispossible(vector<ll> &a, ll mid, ll n, ll k) {
    ll partitions = 1, runningSum = 0;

    for (ll i = 0; i < n; i++) {
        if (runningSum + a[i] > mid) {
            partitions++;
            runningSum = a[i];
            if (partitions > k) return false;
        } else {
            runningSum += a[i];
        }
    }
    return true;
}

ll solve(vector<ll> &a, ll n, ll k) {
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll left = *max_element(a.begin(), a.end());
    ll right = sum;

    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (ispossible(a, mid, n, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << solve(a, n, k) << '\n';
    return 0;
}


