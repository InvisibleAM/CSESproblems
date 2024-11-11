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

// Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
// Input
// The first input line has an integer n: the size of the grid.
// After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
// Output
// Print the number of paths modulo 10^9+7.

void paths(int i, int j, int n, vvi grid){
    vvi dp(n,vi(n,0));
    int ans1=0; 
    int ans2=0;
    if(grid[i-1][j] == '.') ans1 = dp[i-1][j];
    if(grid[i][j-1] == '.') ans2 = dp[i][j-1];

    dp[i][j] = ans1 + ans2;
}


int main() {
    int n;
    cin >> n;

    vvi grid(n,vi(n));
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }
    int ans;
    vvi dp(n,vi(n,0));
    paths(n,n,n,grid);
    ans = dp[n][n];

    

    cout << ans << endl;
}