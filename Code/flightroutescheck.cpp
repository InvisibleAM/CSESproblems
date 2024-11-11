#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            visited[u] = true;
            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

bool isStronglyConnected(int n, vector<vector<int>>& adj, vector<vector<int>>& adj_rev) {
    vector<bool> visited(n + 1, false);
    dfs(1, adj, visited);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO\n1 " << i << endl;
            return false;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(1, adj_rev, visited);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO\n" << i << " 1" << endl;
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adj_rev(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    if (isStronglyConnected(n, adj, adj_rev)) {
        cout << "YES" << endl;
    }

    return 0;
}