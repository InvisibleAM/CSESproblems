#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define ll long long
#define pll pair<long long, long long>
#define vll vector<long>
#define vvll vector<vector<long long>>
#define f first
#define s second
using namespace std;

ll n,m,k;

vector<vector<ii>> adj;
vector<vector<ll>> dist;

void dijkstra(int src) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});
    dist[src][0] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u][k-1]) continue;

        for (auto &[v, w] : adj[u]) {
            ll new_dist = d + w;
            if (new_dist < dist[v][k-1]) {
                dist[v][k-1] = new_dist;
                pq.push({new_dist, v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n + 1);
    dist.assign(n + 1, vector<ll>(k, LLONG_MAX));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(1);

    for (int i = 0; i < k; ++i) {
        cout << dist[n][i] << " ";
    }
    cout << endl;

    return 0;
}
