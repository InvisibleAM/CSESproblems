#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int maxN = 100001;

vvi adj(maxN);
vector<bool> vis(maxN, false);
vi parent(maxN);
vi color(maxN);
int n,m, start, end;

bool dfs(int v, int p) {
    vis[v] = true ;
    parent[v] = p; 
    color[v] = 1;
    for (int u : adj[v]){
        if(color[u]==1){ 
            vi res;
            int x = v;
            while(x != u){
                res.push_back(x);
                x = parent[x];
            }
            res.push_back(x);
            res.push_back(res[0]);
            cout << res.size() << endl;
            reverse(res.begin(),res.end());
            for(auto x: res) cout << x << " ";
        }
        else if(color[u]==0){
            bool temp = dfs(u,v);
            if (temp == true)
            {
                vi res;
                int x = parent[u];
                while (parent[x] != u)
                {
                    res.push_back(x);
                    x = parent[x];
                }
                cout << res.size() << "\n";
                reverse(res.begin(), res.end());
                for (auto x : res)
                    cout << x << " ";
                exit(0);
                return true;
            }
        }
    }
    color[v] = 2;
    return false;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, -1);
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

