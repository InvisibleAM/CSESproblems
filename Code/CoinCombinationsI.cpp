#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n,x;
    std::cin >> n >> x;
    std::vector<int> coins;
    for(int i =0; i<n; i++){
        int temp;
        std::cin >> temp;
        coins.push_back(temp);
    }


    std::vector<long long> dp(x+1,0);
    dp[0]=1;

    for (int weight = 0; weight <= x; weight++) {
		for (int i = 1; i <= n; i++) {
			if (weight - coins[i - 1] >= 0) {
				dp[weight] += dp[weight - coins[i - 1]];
                dp[weight] %= MOD;
			}
		}
	}


    int ans = dp[x];
    std::cout << ans << std::endl;
    return 0;
}