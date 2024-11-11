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
ll n, m;
vector<tuple<int, int, ll>> edges;
vector<vector<pair<ll, ll>>> adj(n + 1);
vector<vector<ll>> dist(n + 1, vector<ll>(2,INF));
vector<bool> vis(n+1);
priority_queue<vector<ll>, vector<vector<ll>> , greater <vector<ll>>> pq;

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a % b);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        ll x;
        cin >> a >> b >> x;
        adj[a].push_back({b,x});
    }
    dist[1][0] = 0; // [node][used]
    dist[1][1] = 0; // [node][avilable]

    pq.push({0,1,1}); //[dist, node, avil]

    while(pq.size()>0){
        auto it = pq.top();  
        pq.pop(); 
        ll d = it[0]; 
        ll node = it[1];
        ll avil = it[2];

        if(dist[node][avil] < d) continue;
        for(auto ch: adj[node]){ //check adjacent
            if(avil == 1){ // if node is avil
                if(dist[ch.first][1] > d + ch.second){
                    dist[ch.first][1] = d + ch.second;
                    pq.push({dist[ch.first][1], ch.first, 1});
                }
                if (dist[ch.first][0] > (d + (ch.second) / 2))
                {
                    dist[ch.first][0] = (d + (ch.second) / 2);
                    pq.push({dist[ch.first][0], ch.first, 0});
                }
            }
            else{
                if (dist[ch.first][0] > (d + (ch.second)))
                {
                    dist[ch.first][0] = (d + (ch.second));
                    pq.push({dist[ch.first][0], ch.first, 0});
                }
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << endl;


}