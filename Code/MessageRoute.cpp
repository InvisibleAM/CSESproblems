#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;

//dijsktra

int main() {
    //input
    int n,m;
    cin >> n >> m;

    vvi adj;
    for (int i = 0 ; i < m; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
    }
    //solution (min path between 1 and n)
    vector<bool> vis(n+1, false);
    vi dist(n+1);

    queue<int> q;
    vi parent(n+1);
    q.push(1);
    dist[1] = 0;
    vis[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = true;

        for (int v : adj[u]){
            if (!vis[v]){
                dist[v] = dist[u] + 1;
                vis[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(!vis[n]) cout << "IMPOSSIBLE" << endl;
    else {
        int x = n;
        int k = dist[n];
        vi ans(k+1);
        for(int i = k; i >= 0; i--){
            ans[i] = x;
            x = parent[x];
        }
        cout << k+1 << endl;
        for (int i = 0; i <= k; i++){
            cout << ans[i] << " ";
        }
    }
    
}

//shortest path using bfs