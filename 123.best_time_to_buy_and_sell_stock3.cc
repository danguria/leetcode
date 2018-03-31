#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        int maxProfit(vector<int>& prices)
        {
            int N = prices.size();
            if (N < 1) return 0;

            int **DP = new int*[2+1];
            for (int i = 0; i < 2+1; i++)
                DP[i] = new int[N];

            for (int i = 0; i < N; i++)
                DP[0][i] = 0;
            DP[1][0] = DP[2][0] = 0;

            for (int i = 1; i <= 2/*i < N*/; i++) {
                int maxDiff = -prices[0] + DP[i][0]; // = -prices[0];
                for (int j = 1; j < N; j++) {
                    DP[i][j] = max(DP[i][j-1], prices[j] + maxDiff);
                    maxDiff = max(maxDiff, -prices[j] + DP[i-1][j]);
                }
            }

            return DP[2][N-1];
        }
        int maxProfit2(vector<int>& prices)
        {
            int N = prices.size();
            if (N < 1) return 0;

            int **DP = new int*[2+1];
            for (int i = 0; i < 2+1; i++)
                DP[i] = new int[N];

            for (int i = 0; i < N; i++)
                DP[0][i] = 0;
            DP[1][0] = DP[2][0] = 0;

            for (int i = 1; i <= 2/*i < N*/; i++) {
                for (int j = 1; j < N; j++) {
                    int mm = 0;
                    int mi = 0;
                    for (int m = 0; m < j; m++) {
                        //cout << i << ", " << j << ", " << m << endl;
                        int tmp = prices[j] - prices[m] + DP[i-1][m];
                        if (prices[j] - prices[m] + DP[i-1][m] > mm) {
                            mm = tmp;
                            mi = m;
                        }
                    }

                    DP[i][j] = max(DP[i][j-1], mm);
                }
            }

            return DP[2][N-1];
        }
};

int main()
{
    //vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    //vector<int> prices;
    //vector<int> prices = {1};
    Solution s;

    cout << s.maxProfit(prices) << endl;
    return 0;
}
