#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '#'){
        return;
    }
    visited[i][j] = true;
    dfs(grid, visited, i+1, j, n, m);
    dfs(grid, visited, i-1, j, n, m);
    dfs(grid, visited, i, j+1, n, m);
    dfs(grid, visited, i, j-1, n, m);
}

int main() {
    //input
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }

    // solution
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                dfs(grid, visited, i, j, n, m);
                rooms++;
            }
        }
    }


    
    // output
    cout << rooms << endl; // 
    return 0;
}