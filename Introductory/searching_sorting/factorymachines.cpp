#include <bits/stdc++.h>

using namespace std;

//binary search on answer

//T.C - O(nlog(max(a)*t))
//S.C - O(1)

int main(){
    
    long long n, t;
    cin >> n >> t;
    long long a[n];

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    //r = t*a[0] because the maximum time taken by the first machine(which is samllest) to produce t products
    long long l = 1, r = t*a[0], ans = t*a[0];

    while(l <= r){
        long long mid = l + (r-l)/2;
        long long sum = 0;
        for(long long i = 0; i < n; i++){
            sum += mid/a[i];
            if(sum >= t){
                break;
            }
        }
        if(sum >= t){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}