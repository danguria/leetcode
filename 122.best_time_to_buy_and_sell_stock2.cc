#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() < 1) return 0;

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
};


int main()
{

    //vector<int> prices = {7, 1, 5, 3, 6, 4};
    //vector<int> prices = {1};
    vector<int> prices = {4, 1, 2};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
