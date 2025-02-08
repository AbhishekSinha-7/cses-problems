#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;

    priority_queue<pair<int,  int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pq1.push({a, b});
    }

    int ans = 0;

    while(!pq1.empty()){
        pair<int, int> p = pq1.top();
        pq1.pop();

        pq2.push(p.second);

        while(!pq2.empty() && pq2.top() < p.first){
            pq2.pop();
        }

        ans = max(ans, (int)pq2.size());
        

    }

    cout << ans << endl;

    return 0;
}