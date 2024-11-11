#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define ll long long
#define pll pair<long long, long long>

using namespace std;

//idea: shortest path in directed graphs

const ll INF = 1e18;

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a; --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (dist[a][b] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[a][b] << "\n";
        }
    }

    return 0;
}