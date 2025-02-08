#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        a[i] = current_sum;
    }

    unordered_map<long long, bool> mp(false);

    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            mp[a[i]] = true;
            mp[a[j] - a[i]] = true;
        }
    }

    int maxi = *max_element(a, a+n);

    for(int i = 1; i <= maxi; i++) {
        if(mp[i] == false) {
            cout << i << endl;
            return 0;
        }
    }

}