#define sz(a) (int)(a).size()
using vi = vector<int>;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 2 approaches: sorting or heap, both same time complexity but sorting with quicksort uses O(1) additional space, whereas the heap uses O(k) space in addition to the output list
        auto cmp = [](const vi &a, const vi &b) -> bool {
            double d1 = sqrt((double)(a[0]) * a[0] + (double)a[1] * a[1]);
            double d2 = sqrt((double)(b[0]) * b[0] + (double)b[1] * b[1]);
            return d1 < d2;
        };
        
        sort(points.begin(), points.end(), cmp);
        return vector<vi>(points.begin(), points.begin() + k);
    }
};
