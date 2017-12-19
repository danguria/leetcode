#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {

            sort(nums.begin(), nums.end());

            int size = nums.size();
            int closest = INT_MAX;
            int ans;

            for (int i = 0; i < size - 2; i++) {

                int t = -(nums[i] - target);

                int head = i + 1;
                int tail = size - 1;
                
                while (head < tail) {
                   int sum = nums[head] + nums[tail];
                   if (t == sum) return target;

                   if (abs(target - (nums[i] + sum)) < closest) {
                       closest = abs(target - (nums[i] + sum));
                       ans = nums[i] + sum;
                       //cout << "candi: " << nums[i] << " + " << nums[head] << " + " << nums[tail] << endl;
                   }
                   
                   if (sum < t) head++;
                   else tail--;
                }
            }

            return ans;
        }
};

int main() {

    Solution s;
    vector<int> n1 = {-1, 2, 1, -4};
    cout << s.threeSumClosest(n1, 1) << endl; // 2
    cout << s.threeSumClosest(n1, 2) << endl; // 2
    cout << s.threeSumClosest(n1, 3) << endl; // 2
    cout << s.threeSumClosest(n1, -44) << endl; // -4

    return 0;
}
