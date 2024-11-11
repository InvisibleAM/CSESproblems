#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;

//detecting bipirtite graph

int main() {
    //input
    int n, m;
    cin >> n >> m;

    vvi adj(n + 1);
    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    //solution
    vector<int> color(n + 1, -1);
    bool isBipartite = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start coloring with 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // Alternate colors
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        isBipartite = false; // Found same color in adjacent nodes
                        break;
                    }
                }
                if (!isBipartite) break; // Exit if not bipartite
            }
        }
        if (!isBipartite) break; // Exit if not bipartite
    }

    //output (print for each node)
    if (isBipartite) {
        for (int i = 1; i <= n; i++) {
            cout << 1+ color[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}