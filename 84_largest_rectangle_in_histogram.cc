#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        /* T(n) = O(n!)
        int largestRectangleArea(vector<int>& heights) {
            int max_area = 0;

            for (int i = 0; i < heights.size(); i++) {
                int min_height = INT_MAX;
                for (int j = i; j < heights.size(); j++) {
                    int w = j - i + 1;
                    min_height = heights[j] < min_height ? heights[j] : min_height;
                    int area = w * min_height;
                    max_area = max_area > area ? max_area : area;
                }
            }
            return max_area;
        }
        */

        int area(vector<int>& heights, int l, int r, int size) {
            if (size == 1) return heights[l];
            int m = (size / 2 - 1) + l;

            int area_l = area(heights, l, m, m - l + 1);
            int area_r = area(heights, m + 1, r, r - m);

            int w, h = INT_MAX, area_t = INT_MIN;
            int i = m, j = m + 1;
            //std::cout << "l: " << l << ", r: " << r << ", size: " << size << std::endl;
            while (i >= l && j <= r) {
                h = std::min(h, std::min(heights[i], heights[j])); 
                w = j - i + 1;
                area_t = std::max(area_t, w * h);
                //std::cout << "i: " << i << ", j: " << j << ", w: " << w << ", h: " << h << ", area: " << area_t << std::endl;
                if (i == l) j++;
                else if (j == r) i--;
                else {
                    if (heights[i-1] > heights[j+1])
                        i--;
                    else j++;
                }
            }
            

            return std::max(std::max(area_l, area_r), area_t);
        }

        int largestRectangleArea(vector<int>& heights) {
            if (heights.empty()) return 0;
            return area(heights, 0, heights.size() - 1, heights.size());
        }
};

int main() {
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "answer : " << s.largestRectangleArea(heights) << endl;
    heights = {4,2,0,3,2,4,3,4};
    cout << "answer : " << s.largestRectangleArea(heights) << endl;
    heights = {1, 1};
    cout << "answer : " << s.largestRectangleArea(heights) << endl;

    return 0;
}
