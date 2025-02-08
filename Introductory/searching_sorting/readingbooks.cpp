#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){

    ll n;
    cin >> n;
    ll a[n];

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    ll maxi = a[n-1];
    ll sum = 0;

    for(ll i = 0; i < n-1; i++){
        sum += a[i];
    }

    if(maxi > sum){
        cout << maxi*2 << endl;
    } else {
        cout << sum + maxi << endl;
    }

    return 0;
}