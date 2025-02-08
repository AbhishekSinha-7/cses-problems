#include <bits/stdc++.h>
#define ll long long
using namespace std;

// function to find the minimum number of towers
ll solve(ll N, vector<ll>& cubes)
{
    // Variable to store the number of twers
    ll ans = 0;

    // Multiset to store the size of top most cubes of all
    // towers
    multiset<ll> topElements;
    for (int i = 0; i < N; i++) {
        // Find the smallest cube which is larger than
        // cubes[i]
        auto it = topElements.upper_bound(cubes[i]);
        // If no cube has size > cubes[i], then we need
        // another tower for this block
        if (it == topElements.end()) {
            ans++;
            topElements.insert(cubes[i]);
        }
        // If there is a cube which has size > cubes[i],
        // place cubes[i] on top of it.
        else {
            topElements.erase(it);
            topElements.insert(cubes[i]);
        }
    }
    return ans;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> cubes(N);
    for (int i = 0; i < N; i++) {
        cin >> cubes[i];
    }

    cout << solve(N, cubes);
}