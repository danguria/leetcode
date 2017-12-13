#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // Using brute force T(n) = n^3 * n
        /*
        vector<vector<int>> threeSum(vector<int>& nums) {

            vector<vector<int>> anss;
            int size = nums.size();
            if (size < 3) return anss;

            for (int i = 0; i < size - 2; i++) {
                for (int j = i + 1; j < size - 1; j++) {
                    for (int k = j + 1; k < size; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> l;
                            l.push_back(nums[i]);
                            l.push_back(nums[j]);
                            l.push_back(nums[k]);
                            sort(l.begin(), l.end());
                            bool duplicated = false;
                            for (auto ans : anss)
                                if (ans[0] == l[0] && ans[1] == l[1] && ans[2] == l[2])
                                    duplicated = true;
                            if (!duplicated)
                                anss.push_back(l);
                        }
                    }
                }
            }

            return anss;
        }
        */

        /* FAILURE
         * I am going to use the function twoSum that I wrote in problem 01.
         * Let answer be a vector this function will return
         * For each item n in S
         *     Let n be a target for twoSum function, and 
         *       call twoSum with inputs nums - {n} and n
         *     Let result be a vector returned by twoSum
         *     If result is not empty,
         *       add every item in result to visited map,
         *       and then add n to result,
         *       and then add result to the answer
         */
        /*
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> answer, ret;
            set<int> visited_nums;
            for (int i = 0; i < nums.size(); i++) {

                if (visited_nums.find(nums[i]) == visited_nums.end()) {
                    vector<vector<int>> result = twoSum(nums, i);
                    for (auto twosum : result) {
                        visited_nums.insert(nums[i]);
                        visited_nums.insert(nums[twosum[0]]);
                        visited_nums.insert(nums[twosum[1]]);
                        twosum.push_back(i);
                        answer.push_back(twosum);
                    }
                }
            }

            for (auto threesum : answer) {
                vector<int> tmp;
                tmp.push_back(nums[threesum[0]]);
                tmp.push_back(nums[threesum[1]]);
                tmp.push_back(nums[threesum[2]]);
                ret.push_back(tmp);
            }

            return ret;
        }
        
        vector<vector<int>> twoSum(vector<int>& nums, int target_index) {
            // map<int, int>
            // for each n in nums
            //    remain = target - index of n;
            //    if map has remain as a key
            //        return index of n and the value of remain stored in map
            //    else
            //        store (n, index of n) to the map
            //
            unordered_map<int, int> map;
            set<int> visited_idx;
            vector<vector<int>> answer;
            int target = -(nums[target_index]);

            for (int i = 0; i < nums.size(); i++) {
                if (i == target_index || visited_idx.find(i) != visited_idx.end()) 
                    continue;
                int remain = target - nums[i];

                if (map.find(remain) != map.end()) {
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(map[remain]);
                    visited_idx.insert(i);
                    visited_idx.insert(map[remain]);
                    answer.push_back(result);

                    // erase key-value
                    map.erase(remain);
                } else {
                    map[nums[i]] = i;
                }
            }
            return answer;
        }
        */

        vector<vector<int>> threeSum(vector<int>& nums) {

            vector<vector<int>> answer;

            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++) {
                int target = -(nums[i]);
                int front = i + 1;
                int back = nums.size() - 1;

                while (front < back) {
                    int sum = nums[front] + nums[back];

                    if (sum < target) {
                        front++;
                    } else if (sum > target) {
                        back--;
                    } else {
                        vector<int> triplet(3, 0);
                        triplet[0] = nums[i];
                        triplet[1] = nums[front];
                        triplet[2] = nums[back];

                        answer.push_back(triplet);

                        // skip duplicate numbers for triplet[1]
                        while (front < back && nums[front] == triplet[1]) front++;

                        // skip duplcate numbers for triplet[2]
                        while (front < back && nums[back] == triplet[2]) back--;
                    }
                }

                // skip duplicate numbers for triplet[0]
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
            }
            return answer;
        }
};

void print_result(vector<vector<int>> ans) {
    for (int i = 0; i < ans.size(); i++) {
        vector<int> l = ans[i];
        for (int i : l) cout << i << ", ";
        cout << endl;
    }
}

int main() {

    vector<int> n1 = { -1, 0, 1, 2, -1, -4 };
    vector<int> n2 = { 0, 0, 0, 0 };
    vector<int> n3 = { 3, 0, -2, -1, 1, 2 };
    vector<int> n4 = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
    
    Solution s;
    print_result(s.threeSum(n1));
    cout << endl;
    print_result(s.threeSum(n2));
    cout << endl;
    print_result(s.threeSum(n3));
    cout << endl;
    print_result(s.threeSum(n4));
    return 0;
}
