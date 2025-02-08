#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

    ll n;
    cin >> n;

    ll a[n];
    ll b[n];

    for(ll i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }

    sort(a, a+n);

    ll currtime = 0;
    ll ans = 0;

    for(ll i = 0; i < n; i++){
        currtime += a[i];
        ans += b[i] - currtime;
    }

    cout << ans << endl;
    return 0;
}