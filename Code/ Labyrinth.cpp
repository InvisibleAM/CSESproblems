#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair


int main() {
    //input
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    pair <int,int> start,end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
            if (c == 'A') start = make_pair(i,j);
            else if (c == 'B') end = make_pair(i,j);
        }
    }

    // solution
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    vector<char> dir;

    q.push(start);
    vis[start.first][start.second] = true;

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        ii v1 = mp(u.first, u.second + 1); // right
        if(v1.f < 0 || v1.f >= n || v1.s < 0 || v1.s >= m) continue;
        if (grid[v1.f][v1.s] == '#') continue;
        if (vis[v1.f][v1.s]) continue;
        vis[v1.f][v1.s] = true;
        dir.push_back('R');
        q.push(v1);

        ii v2 = mp(u.first-1, u.second ); // Up
        if(v2.f < 0 || v2.f >= n || v2.s < 0 || v2.s >= m) continue;
        if (grid[v2.f][v2.s] == '#') continue;
        if (vis[v2.f][v2.s]) continue;
        vis[v2.f][v2.s] = true;
        dir.push_back('U');
        q.push(v2);

        ii v3 = mp(u.first+1, u.second ); // down
        if(v3.f < 0 || v3.f >= n || v3.s < 0 || v3.s >= m) continue;
        if (grid[v3.f][v3.s] == '#') continue;
        if (vis[v3.f][v3.s]) continue;
        vis[v3.f][v3.s] = true;
        dir.push_back('D');
        q.push(v3);

        ii v4 = mp(u.first, u.second - 1); // left
        if(v4.f < 0 || v4.f >= n || v4.s < 0 || v4.s >= m) continue;
        if (grid[v4.f][v4.s] == '#') continue;
        if (vis[v4.f][v4.s]) continue;
        vis[v4.f][v4.s] = true;
        dir.push_back('L');
        q.push(v4);



    // output
    if (vis[end.f][end.s]) {
		cout << "YES" << endl;
		cout << dir.size() << endl;
        for (char d : dir) {
            cout << d;
        }
		cout << endl;
	} 
    else {
		cout << "NO" << endl;
	}
    return 0;
    }
}