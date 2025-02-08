#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a}); // Store as {ending time, starting time}.
    }

    // Sort movies based on their ending time.
    sort(movies.begin(), movies.end());

    int temp = 0; // Tracks the end time of the last selected movie.
    int ans = 0;  // Tracks the count of movies that can be watched.

    for (auto movie : movies) {
        if (movie.second >= temp) { // If the movie starts after or when the last one ends.
            temp = movie.first;    // Update the end time.
            ans++;                 // Increment the count of selected movies.
        }
    }

    cout << ans << endl;

    return 0;
}
