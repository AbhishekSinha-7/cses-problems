#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// function to find the minimum number of rooms and the
// rooms allocated to each customer
void solve(vector<vector<ll> >& timings, ll N)
{
    // vector to store the {arrival, departure, index} of
    // all customers
    vector<vector<ll> > vec(N, vector<ll>(3));
    for (int i = 0; i < N; i++) {
        vec[i][0] = timings[i][0];
        vec[i][1] = timings[i][1];
        vec[i][2] = i;
    }

    // Sort the vector according to the arrival time of
    // customers
    sort(vec.begin(), vec.end());

    // Min heap to store {departure, room number} to fetch
    // the room which gets vacant the earliest
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >,
                greater<pair<ll, ll> > >
        occupiedRooms;

    // Variable to store the total number of rooms needed
    int roomCnt = 0;

    // vector to store the room alloted to each customer
    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        ll arrivalTime = vec[i][0];
        ll departureTime = vec[i][1];
        ll idx = vec[i][2];

        // Check if there are no rooms available or all the
        // rooms are occupied
        if (occupiedRooms.empty()
            || occupiedRooms.top().first >= arrivalTime) {
            // If there are no rooms or all the rooms are
            // occupied, then increment the total number of
            // rooms needed and allocate the room to the
            // current customer
            roomCnt += 1;
            occupiedRooms.push({ departureTime, roomCnt });
            ans[idx] = roomCnt;
        }
        else {
            // If there is a vacant room, then assign that
            // vacant room to the current customer
            int vacantRoom = occupiedRooms.top().second;
            occupiedRooms.pop();
            occupiedRooms.push(
                { departureTime, vacantRoom });
            ans[idx] = vacantRoom;
        }
    }

    // Print the total rooms needed along with the room
    // allocated to each customer
    cout << roomCnt << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    // Sample Input
    int N;
    cin >> N;
    vector<vector<ll> > timings(N, vector<ll>(2));
    for (int i = 0; i < N; i++) {
        cin >> timings[i][0] >> timings[i][1];
    }

    solve(timings, N);
    // your code goes here
    return 0;
}
