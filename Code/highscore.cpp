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

const ll INF = 1e18;
int n, m;
vector<tuple<int, int, ll>> edges;
vvi adj;
vvi adj2;
vector<ll> dist(n + 1, INF);
vector<bool> vis(n+1);
vector<bool> vis2(n+1);

void dfs(int v){
    if(vis[v]) return;
    vis[v] = true;
    for(auto u : adj[v]){
        dfs(u);
    }
}

void dfs2(int v){
    if(vis2[v]) return;
    vis2[v] = true;
    for(auto u : adj2[v]){
        dfs(u);
    }
}

int main() {
    cin >> n >> m;
    dist[1] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs(1);
    dfs2(n);

    for(int i =0; i<n ; i++){
        for(auto e : edges){
            int a, b;
            ll x;
            tie(a, b, x) = e;
            if(dist[a] != INF && dist[a] + x < dist[b]){
                dist[b] = dist[a] + x;
                if (i == n-1 && vis[b] && vis2[b]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }


    cout << -dist[n] << endl;
    return 0;
}