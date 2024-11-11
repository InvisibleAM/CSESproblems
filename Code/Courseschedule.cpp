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

void findCourseOrder(int n, int m, vector<pair<int, int>>& prerequisites) {
    vvi adj(n + 1);
    vi in_degree(n + 1, 0);
    
    for (auto& pre : prerequisites) {
        adj[pre.first].push_back(pre.second);
        in_degree[pre.second]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vi order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        
        for (int next_course : adj[course]) {
            in_degree[next_course]--;
            if (in_degree[next_course] == 0) {
                q.push(next_course);
            }
        }
    }
    
    if (order.size() == n) {
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> prerequisites(m);
    for (int i = 0; i < m; ++i) {
        cin >> prerequisites[i].first >> prerequisites[i].second;
    }
    
    findCourseOrder(n, m, prerequisites);
    return 0;
}