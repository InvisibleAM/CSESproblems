#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n,x;
    std::cin >> n >> x;
    std::vector<int> coins;
    for(int i =0; i<n; i++){
        int temp;
        std::cin >> temp;
        coins.push_back(temp);
    }


    std::vector<int> dp(x+1,x+1);
    //c has value of coins, x is desired sum
    // dp should print minimum no of coins requred to make x
    dp[0] = 0; // Base case: no coins needed to make sum 0
    
    for(int a=0; a < x +1; a++){
        for(int c: coins){
            if(a - c >= 0){
                dp[a] = std::min(dp[a], dp[a - c] + 1);
            }
        }
    }
    int ans = dp[x] == x+1 ? -1 : dp[x];
    std::cout << ans << std::endl;
    return 0;
}