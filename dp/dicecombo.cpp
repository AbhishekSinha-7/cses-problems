#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;

int t[1000001];

void solve(int n, int sum, int &cnt){
    if(sum == n){
        cnt++;
        return;
    }
    if(sum > n){
        return;
    }

    if(t[sum] != 0){
        cnt = (cnt + t[sum]) % MOD;
        return;
    }

    for(int i = 1; i <= 6; i++){
        solve(n, sum + i, cnt);
    }
}
int main(){

    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    int cnt = 0;

    solve(n, 0, cnt);

    cout << cnt << endl;

    return 0;
}