#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

const ll INF = 10000000000000;
const ll MX = 2e5 + 5;

vector<ll> Adj[MX];
ll dp[2][MX];

void DFS(ll u, ll p) {
    dp[0][u] = 0; //excluding u
    dp[1][u] = 0; //including u

    for (ll v : Adj[u]) {
        if (v == p) continue;

        DFS(v, u);

        dp[0][u] += max(dp[0][v], dp[1][v]); 
    }

    for (ll v : Adj[u]) {
        if (v == p) continue;

        dp[1][u] = max(dp[1][u], dp[0][u] - max(dp[0][v], dp[1][v]) + dp[0][v] + 1); //second term is with edge u-v(1), then excluding v subtree , adding for u,v withut including them
    }
}

int main() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    DFS(1, -1);

    ll ans = max(dp[0][1], dp[1][1]);
    cout << ans << endl;

    return 0;
}
