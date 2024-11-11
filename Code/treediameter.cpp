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

const ll INF = 10000000000000;
const ll MX = 2e5 + 5;

vector<ll> Adj[MX];
ll dp[MX];


ll dfs(ll node, ll parent) {
    ll max1 = 0, max2 = 0; // Variables to store the top two maximum heights of the children
    for (ll neighbor : Adj[node]) { 
        if (neighbor == parent) continue; 
        ll height = dfs(neighbor, node) + 1; // Recursively calculate the height of the subtree
        if (height > max1) { // Update the top two maximum heights
            max2 = max1;
            max1 = height;
        } else if (height > max2) {
            max2 = height;
        }
    }
    dp[node] = max1 + max2; // The maximum path passing through this node is the sum of the top two heights
    return max1; 
}

// Function to find the diameter of the tree
ll findTreeDiameter(ll n) {
    dfs(1, -1); // Start DFS from node 1 with no parent (-1)
    ll diameter = 0; // Variable to store the diameter of the tree
    for (ll i = 1; i <= n; ++i) { // Iterate through all nodes to find the maximum value in dp array
        diameter = max(diameter, dp[i]); // Update the diameter
    }
    return diameter; // Return the diameter of the tree
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

    ll ans = findTreeDiameter(n);
    cout << ans << endl;

    return 0;
}
