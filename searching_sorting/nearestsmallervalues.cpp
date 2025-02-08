#include <bits/stdc++.h>
#define ll long long int

//monotonic stack
//T.C = O(N);       each element is pushed or popped exactly once 
//S.C = O(N);

using namespace std;

int main(){

    ll n;
    cin >> n;

    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    stack<pair<ll, ll>>st;
    ll ans[n];

    for(ll i = 0; i < n; i++){

        while(!st.empty() && st.top().first >= a[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = 0;
        }
        else{
            ans[i] = st.top().second;
        }

        st.push({a[i], i+1});
    }

    for(ll i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}