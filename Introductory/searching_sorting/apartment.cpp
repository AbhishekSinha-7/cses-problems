#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int main(){

    int m, n, k;
    cin >> m >> n >> k;

    int a[m], b[n];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    // Correct way to sort arrays
    sort(a, a + m);
    sort(b, b + n);

    int i = 0, j = 0, count = 0;

    while(i < m && j < n){
        if(abs(a[i] - b[j]) <= k){
            count++;
            i++;
            j++;
        }else if(a[i] < b[j]){
            i++;
        }else{
            j++;
        }
    }

    cout << count << endl;

    return 0;
}