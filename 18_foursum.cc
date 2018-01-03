#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            vector<vector<int>> answer;
            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums.size() - (j + 1) < 2) break;

                    int front = j + 1;
                    int end = nums.size() - 1;

                    int t = target - (nums[i] + nums[j]);
                    while (front < end) {
                        int sum = nums[front] + nums[end];

                        if (sum > t) {
                            end--;
                        } else if (sum < t) {
                            front++;
                        } else { // sum == t
                            vector<int> quadruplet(4, 0);
                            quadruplet[0] = nums[i];
                            quadruplet[1] = nums[j];
                            quadruplet[2] = nums[front];
                            quadruplet[3] = nums[end];

                            answer.push_back(quadruplet);

                            while (front < end && nums[front] == quadruplet[2]) front++;
                            while (front < end && nums[end] == quadruplet[3]) end--;
                        }

                    }
                    while (j + 1 < nums.size() && nums[j + 1] == nums[j]) j++;
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
            }

            return answer;
        }
};


int main() 
{
    Solution s;
    vector<int> nums = {-1,-5,-5,-3,2,5,0,4};
    vector<vector<int>> quadruplets = s.fourSum(nums, -7);
    for (auto q : quadruplets) {
        for (auto i : q) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}
