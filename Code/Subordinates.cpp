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


// Given the structure of a company, your task is to calculate for each employee the number of their subordinates.
// Input
// The first input line has an integer n: the number of employees. The employees are numbered 1,2,\dots,n, and employee 1 is the general director of the company.
// After this, there are n-1 integers: for each employee 2,3,\dots,n their direct boss in the company.
// Output
// Print n integers: for each employee 1,2,\dots,n the number of their subordinates.
// Constraints

// 1 \le n \le 2 \cdot 10^5

// int main(){
//     int n;
//     cin >> n;
//     vvll adj(n+1);
//     for(ll i=2; i<n; i++){
//         int boss;
//         cin >> boss;
//         adj[boss].push_back(i);
//     }
//     vll ans(n+1,0);
//     queue<ll> q;
//     q.push(1);

//     while(!q.empty()){
//         ll node = q.front();
//         q.pop();

//         for(auto child : adj[node]){
//             q.push(child);
//             ans[node] += 1 + ans[child];
//         }
//     }




//     // output
//     for(ll i=1; i<=n; i++){
//         cout<< ans[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Function to perform DFS and count subordinates

void dfs(int node, const vector<vector<int>>& adj, vector<int>& subordinates) {
    for (int child : adj[node]) {
        dfs(child, adj, subordinates);
        subordinates[node] += 1 + subordinates[child];
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    vector<int> subordinates(n + 1, 0);
    dfs(1, adj, subordinates);

    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    cout << endl;
    return 0;
}