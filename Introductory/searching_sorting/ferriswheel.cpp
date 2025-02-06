#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);  // Sort weights in ascending order

    int left = 0;           // Pointer to lightest person
    int right = n - 1;      // Pointer to heaviest person
    int gondolas = 0;

    while(left <= right){
        if(left == right){
            // Only one person left
            gondolas++;
            break;
        }
        
        if(a[left] + a[right] <= x){
            // Can pair lightest and heaviest
            gondolas++;
            left++;
            right--;
        }
        else{
            // Heaviest person must ride alone
            gondolas++;
            right--;
        }
    }

    cout << gondolas << endl;
    return 0;
}