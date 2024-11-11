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

//idea: shortest path using dijkstra
void dijkstra(long long n, vector<vector<ii>>& adj) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    dist[1] = 0;
    pq.push(mp(0, 1));
    
    while (!pq.empty()) {
        long long u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        
        if (d != dist[u]) continue;
        
        for (auto edge : adj[u]) {
            long long v = edge.first;
            long long len = edge.second;
            
            if (dist[u] + len < dist[v]) {
                dist[v] = dist[u] + len;
                pq.push(mp(dist[v], v));
            }
        }
    }
    
    for (long long i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<vector<ii>> adj(n + 1);
    
    for (long long i = 0; i < m; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
    }
    
    dijkstra(n, adj);
    
    return 0;
}