#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i; // Store the position of each number
    }

    int rounds = 1; // At least one round is needed
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }

    cout << rounds << endl;

    return 0;
}
