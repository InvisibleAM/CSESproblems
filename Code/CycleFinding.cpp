#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define mp make_pair
#define ll long long
#define pll pair<long long, long long>
#define vll vector<long>
#define vvll vector<vector<long long>>
#define f first
#define s second
using namespace std;

int maxN = 100001;

vvll edges;
vector<vector<pll>> adj;
ll n,m;

int main() {
    cin >> n >> m;
    for(int i=0; i<m ; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        edges.push_back({a,b,c});
    }   
    vector<ll > dist(n,1e8); 
    for (ll i = 0; i< n-1; i++){
        for (auto it : edges){
            if(dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]]){
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }
    for(auto it : edges){
        if(dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]]){

        }
    }
    bool f = true;
    vector<ll> par(n + 1, -1);
    for (ll i = 0; i < n; i++){
        for (auto edge : edges)
        {
            ll u = edge[0];
            ll v = edge[1];
            ll w = edge[2];
            if (dist[u] != LLONG_MAX)
            {
                ll z = dist[v];
                dist[v] = min(dist[v], dist[u] + w);
                if (dist[v] != z)
                {
                    f = false;
                    par[v] = u;
                }
            }
        }
    }
    if (f)
    {
        cout << "NO" << endl;
    }
    else
    {
        ll x = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (par[i] != -1)
            {
                x = i;
                break;
            }
        }
        vector<ll> cycle;
        unordered_set<ll> st;
        while (st.find(x) == st.end())
        {
            cycle.push_back(x);
            st.insert(x);
            x = par[x];
        }
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        unordered_set<ll> final;
        for (auto &i : cycle)
        {
            cout << i << " ";
            if (final.find(i) != final.end())
            {
                break;
            }
            final.insert(i);
        }
    }
}


