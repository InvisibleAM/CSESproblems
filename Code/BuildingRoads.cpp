#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int n, m;
vector<vector<int>> adj(100001);
vector<bool>vis(100001, false);
vector<int>bridges;

void dfs(int v) {
    vis[v] = true ;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
}



int main() {
    //input
    cin >> n >> m;

    for (int i = 0 ; i < m; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
    }

    for (int i = 1; i <= n; i++) {
      if (vis[i] == false) {
        bridges.push_back(i);
        dfs(i);
      }
    }

    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
      cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
    return 0;

}