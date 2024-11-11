#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define mp make_pair
#define ll long long
#define pll pair<long long, long long>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define f first
#define s second

using namespace std;

unordered_map<ll, ll> parent;
unordered_map<ll, ll> componentSize;
ll numComponents;
ll largestComponent;

ll find(ll a) {
    if (parent[a] != a) {
        parent[a] = find(parent[a]); // Path compression
    }
    return parent[a];
}

// Function to connect two cities using union by size
void connect(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (componentSize[a] < componentSize[b]) swap(a, b);
        parent[b] = a;
        componentSize[a] += componentSize[b];
        componentSize.erase(b); // Remove the smaller component from the map
        numComponents--;
        largestComponent = max(largestComponent, componentSize[a]);
    }
}

// Function to initialize the Union-Find structure
void initialize(ll n) {
    numComponents = n;
    largestComponent = 1;
    for (ll i = 1; i <= n; ++i) {
        parent[i] = i;
        componentSize[i] = 1;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(2));
    for (ll i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    initialize(n);

    for (ll i = 0; i < m; ++i) {
        connect(edges[i][0], edges[i][1]);
        cout << numComponents << " " << largestComponent << endl;
    }

    return 0;
}