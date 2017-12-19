#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int MaxProfit(vector<int>& changes) {

            int dp[changes.size()];
            int max_sum = changes[0];
            dp[0] = changes[0];

            for (int i = 1; i < changes.size(); i++) {
                if (dp[i-1] > 0) {
                    dp[i] = changes[i] + dp[i-1];
                } else {
                    dp[i] = changes[i];
                }
                if (dp[i] > max_sum)
                    max_sum = dp[i];
            }

            return max_sum;
        }

        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;
            vector<int> changes(prices.size(), 0);
            for (int i = 1; i < prices.size(); i++) {
                changes[i-1] = prices[i] - prices[i-1];
            }

            return MaxProfit(changes);
        }

};
int main() {

    Solution s;

    vector<int> prices0 = {};
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 5, 4, 3, 2, 1};
    vector<int> prices3 = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    cout << s.maxProfit(prices0) << endl;
    cout << s.maxProfit(prices1) << endl;
    cout << s.maxProfit(prices2) << endl;
    cout << s.maxProfit(prices3) << endl;
    return 0;
}
