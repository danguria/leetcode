#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            int M = nums1.size();
            int N = nums2.size();

            if (M < N) return findMedianSortedArrays(nums2, nums1);

            int low = 0, high = N*2;

            while (low <= high)
            {
                int mid2 = (low + high) / 2;
                int mid1 = M + N - mid2;

                int L1 = (mid1 == 0)   ? INT_MIN : nums1[(mid1-1)/2];
                int R1 = (mid1 == M*2) ? INT_MAX : nums1[mid1/2];
                int L2 = (mid2 == 0)   ? INT_MIN : nums2[(mid2-1)/2];
                int R2 = (mid2 == N*2) ? INT_MAX : nums2[mid2/2];

                cout << "low = " << low << ", high = " << high << endl;
                cout << "mid1 = " << mid1 << ", mid2 = " << mid2 << endl;
                cout << "L1 = " << L1 << ", R1 = " << R1 << endl;
                cout << "L2 = " << L2 << ", R2 = " << R2 << endl;
                if (L1 > R2) low = mid2 + 1;
                else if (L2 > R1) high = mid2 - 1;
                else return (max(L1, L2) + min(R1, R2)) / 2.0;
            }

            return -1;
        }
};

int main() {

    Solution s;

    // vector<int> n1 = { 900};
    // vector<int> n2 = { 5, 8, 10, 20};
     vector<int> n1 = {1, 3};
     vector<int> n2 = { 2};
//    vector<int> n1 = {2, 4, 6, 8, 10, 12};
//    vector<int> n2 = { 1, 2, 3, 4, 5};
    cout << s.findMedianSortedArrays(n1, n2) << endl;
    return 0;
}
