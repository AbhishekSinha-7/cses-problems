#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll solve(ll n, ll x, vector<ll>& v, ll idx, ll& sum){

    if(idx >= n || sum > x) return 0;

    if(sum == x) return 1;

    ll take = solve(n, x, v, idx, sum + v[idx]);
    ll skip = solve(n, x, v, idx+1, sum);

    return take + skip;


}



int main(){

    ll n, x;
    cin >> n >> x;

    vector<ll>v(n);

    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }

    ll sum = 0;
    ll ans = solve(n, x, v, 0, sum);

    cout << ans << endl;
    return 0;

}