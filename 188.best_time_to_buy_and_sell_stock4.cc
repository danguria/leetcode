#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int maxProfit(int k, vector<int>& prices)
        {
            int N = prices.size();
            if (N <= 1) return 0;

            if (k >= N/2) {
                int minPrice = prices[0];
                int maxPrice = prices[0];
                int maxProfit = 0;
                for (int i = 1; i < prices.size(); i++) {
                    if (prices[i] < maxPrice) {
                        minPrice = maxPrice = prices[i];
                    } else {
                        maxProfit += (prices[i] - prices[i-1]);
                        maxPrice = prices[i];
                    }
                }
                return maxProfit;
            }

            vector<vector<int>> DP;
            DP.resize(k+1, vector<int>(N, 0));

            for (int i = 1; i < k+1; i++) {
                int maxDiff = -prices[0] + DP[i][0]; // = -prices[0];
                for (int j = 1; j < N; j++) {
                    DP[i][j] = max(DP[i][j-1], prices[j] + maxDiff);
                    maxDiff = max(maxDiff, -prices[j] + DP[i-1][j]);
                    cout << "[" << i << "][" << j << "] = " << DP[i][j] << endl;
                }
            }
            return DP[k][N-1];
        }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    //vector<int> prices = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    //vector<int> prices;
    //vector<int> prices = {1};
    Solution s;

    cout << s.maxProfit(2, prices) << endl;
    return 0;
}
