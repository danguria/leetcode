#include <iostream>
#include <vector>
using namespace std;
class Solution {

    public:
        virtual int maxArea(vector<int> &h) = 0;
};

/*
   int size = height.size();
   if (size < 2 ) return 0; // handle simple case
   int max_capacity = INT_MIN;
   int D[size][size];
   for (int i = 0; i < size; i++) D[i][i] = 0;

   for (int gap = 1; gap <= size - 1; gap++) {
   int i = 0, j = i + gap;
   while (i < size && j < size) {
   int capacity = max(D[i][j-1], D[i+1][j]);
   D[i][j] = max(capacity, gap * min(height[i], height[j]));
   max_capacity = max(max_capacity, D[i][j]);
   i++; j++;
   }
   }
   return max_capacity
 */

class DP : public Solution {
    public:

        virtual int maxArea(vector<int>& h) {

            int size = h.size();
            if (size < 2 ) return 0; // handle simple case

            int max_capacity = INT_MIN;
            vector<int> prev(size, 0);
            vector<int> curr(size, 0);

            int gap = 1;
            while (gap < size) {
                for (int i = 0; i < size - gap; i++) {
                    int capacity = max(prev[i], prev[i+1]);
                    capacity = max(capacity, gap * min(h[i], h[i+gap]));
                    max_capacity = max(max_capacity, capacity);
                    curr[i] = capacity;
                    /*
                    cout << "gap : " << gap << endl;
                    cout << "prev[" << i << "] : " << prev[i] << endl;
                    cout << "prev[" << i+1 << "] : " << prev[i+1] << endl;
                    cout << "h[" << i << "] : " << h[i] << endl;
                    cout << "h[" << i+gap << "] : " << h[i+gap] << endl;
                    cout << "capacity: " << capacity << endl;
                    */
                }

                /*
                for (int i = 0; i < size - gap; i++) {
                    cout << curr[i] << " ";
                }
                cout << endl;
                */
                swap(prev, curr);
                gap++;
            }
            return max_capacity;
        }
};

class Ntime : public Solution {
    public:
        virtual int maxArea(vector<int>& h) {

            int max_capacity = INT_MIN;
            int i = 0;
            int j = h.size() -1;

            while (i < j) {
                int height = min(h[i], h[j]);
                max_capacity = max(max_capacity, (j - i) * height);
                while (h[i] <= height && i < j) i++;
                while (h[j] <= height && i < j) j--;
            }
            return max_capacity;
        }
};

void execute(Solution& s) {
    vector<int> h = {1, 2, 4, 3};
    cout << s.maxArea(h) << endl;
}

int main() {

    Ntime t;
    execute(t);

    return 0;
}
