#include <iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define ll long long
#define pll pair<long long, long long>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define f first
#define s second
using namespace std;

vector<int> adj[200001];
int m1[200001];   
int m2[200001]; 
int c[200001];         

void dfs(int v, int p) {
    m1[v] = 0;
    m2[v] = 0;
    for (auto x : adj[v]) {
        if (x == p) continue;
        dfs(x, v);
        if (m1[x] + 1 > m1[v]) {
            m2[v] = m1[v];
            m1[v] = m1[x] + 1;
            c[v] = x;
        } else if (m1[x] + 1 > m2[v]) {
            m2[v] = m1[x] + 1;
        }
    }
}

void dfs2(int v, int p) {
    for (auto x : adj[v]) {
        if (x == p) continue;
        if (c[v] == x) {
            if (m1[x] < m2[v] + 1) {
                m2[x] = m1[x];
                m1[x] = m2[v] + 1;
                c[x] = v;
            } else {
                m2[x] = max(m2[x], m2[v] + 1);
            }
        } else {
            m2[x] = m1[x];
            m1[x] = m1[v] + 1;
            c[x] = v;
        }
        dfs2(x, v);
    }
}


int main() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
	dfs2(1, -1);

    for (int i = 1; i <= n; i++) { cout << m1[i] << " "; }

    return 0;
}
