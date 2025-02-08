#include <bits/stdc++.h>
#define ll long long int

//Inserting n tickets → O(nlog(n));
//finding and erasing a ticket for each customer --> O(mlog(n));
//T.C ---> O((m+n)log(n))


using namespace std;

int main(){

    ll n;
    cin >> n;

    ll m;
    cin >> m;

    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll b[m];
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }

    multiset<ll>s;              //multiset to store duplicates value also
   
    for(ll i = 0; i < n; i++){
        s.insert(a[i]);
    }    
    
    ll ans[m];

    for(ll i = 0; i < m; i++){

        auto it = s.upper_bound(b[i]);         //auto it (return type of iterator be auto)  and upperbound as we want equal or less than value

        if(it != s.begin()){
            it--;           //we got a smaller or equal value
            ans[i] = *it;
            s.erase(it);
        }
        else{       //we got first value of the set , hence it is clear that no value equal to or less exist in the multiset
            ans[i] = -1;
        }
    }

    for(ll i = 0; i < m; i++){
        cout << ans[i] << endl;
    }

    return 0;
}