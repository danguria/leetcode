#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
    public:
        // 115ms
        vector<int> twoSum1(vector<int>& nums, int target) {
            int size = nums.size();
            vector<int> answer;
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (nums[i] + nums[j] == target) {
                        answer.push_back(i);
                        answer.push_back(j); // second
                        return answer;
                    }
                }
            }
            return answer;
        }

        // 6ms
        vector<int> twoSum2(vector<int>& nums, int target) {
            // map<int, int>
            // for each n in nums
            //    remain = target - index of n;
            //    if map has remain as a key
            //        return index of n and the value of remain stored in map
            //    else
            //        store (remain, index of n) to the map
            //
            unordered_map<int, int> map;
            vector<int> answer;

            for (int i = 0; i < nums.size(); i++) {
                int remain = target - nums[i];

                if (map.find(remain) != map.end()) {
                    answer.push_back(i);
                    answer.push_back(map[remain]);
                    return answer;
                }
                map[nums[i]] = i;
            }
            return answer;
        }

};
int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    vector<int> answer;
    answer = s.twoSum2(nums, 9);
    for (int x : answer) {
        cout << x << endl;
    }

    return 0;
}
