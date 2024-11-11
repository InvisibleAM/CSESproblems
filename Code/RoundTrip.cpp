#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int maxN = 100001;;

vvi adj(maxN);
vector<bool> vis(maxN, false);
vi parent(maxN);
int n,m, start, end;

void dfs(int v, int p) {
    vis[v] = true ;
    parent[v] = p;
    for (int u : adj[v]){
        if (!vis[u]) dfs(u, v);
        else if (u != p) {
            vi cycle;
            int cur = v;
            cycle.push_back(v);
            while (parent[cur] != u) {
                cur = parent[cur];
                cycle.push_back(cur);
            }
            cycle.push_back(u);
            cycle.push_back(v);
            cout << cycle.size() << endl;
            for (int x : cycle) cout << x << " ";
            exit(0);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, -1);
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

