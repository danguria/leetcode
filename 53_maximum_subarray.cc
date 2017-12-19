#include <iostream>
#include <vector>
using namespace std;

class SubArray{
    public:
        SubArray() {}
        SubArray(int l, int h, int s) {
            low = l; high = h; sum = s;
        }

        bool operator>=(const SubArray& sub) const {
            return sum >= sub.sum;
        }

        void operator=(const SubArray& sub) {
            low = sub.low;
            high = sub.high;
            sum = sub.sum;
        }

        int low, high;
        int sum;
};

class Solution {
    public:
        SubArray maxSubarray(vector<int>& nums, int low, int high) {
            if (low == high) // base case
                return SubArray(low, high, nums[low]);

            SubArray left_sub, right_sub, cross_sub;
            int mid = (low + high) / 2;
            left_sub = maxSubarray(nums, low, mid);
            right_sub = maxSubarray(nums, mid + 1, high);
            cross_sub = maxCrossSubarray(nums, low, mid, high);

            if (left_sub >= right_sub && left_sub >= cross_sub) {
                return left_sub;
            } else if (right_sub >= left_sub && right_sub >= cross_sub) {
                return right_sub;
            } else {
                return cross_sub;
            }
        }

        SubArray maxCrossSubarray(vector<int>& nums, int low, int mid, int high) {
            int left_sum = INT_MIN;
            int left_low = mid;
            int sum = 0;
            for (int i = mid; i >= low; i--) {
                sum = sum + nums[i];
                if (sum > left_sum) {
                    left_sum = sum;
                    left_low = i;
                }
            }

            int right_sum = INT_MIN;
            int right_high = mid;
            sum = 0;
            for (int j = mid + 1; j <= high; j++) {
                sum = sum + nums[j];
                if (sum > right_sum) {
                    right_sum = sum;
                    right_high = j;
                }
            }

            return SubArray(left_low, right_high, left_sum + right_sum);
        }

        int maxSubarray(vector<int>& nums) {
            SubArray ans = maxSubarray(nums, 0, nums.size() - 1);
            return ans.sum;
        }
};
int main() {
    Solution s;
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    cout << s.maxSubarray(nums1) << endl;
    cout << s.maxSubarray(nums2) << endl;

    return 0;
}
