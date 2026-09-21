#define sz(a) (int)(a).size()

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Intuition: find the net gas value at each station; find a starting position that maximizes the net amount of gas I start with
        // [-1, 0, -1, 3]
        // First of all, the net sum of gas values must be nonnegative, but does that guarantee a solution? At no point in time can my gas tank fall below 0
        // Idea: start checking for starting points at some arbitrary point; track the cumulative sum; if that value drops below 0, move the potential starting point to the first nonnegative value after the current index and mark every index considered so far as non-candidates for starting points
        int n = sz(gas);

        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += gas[i] - cost[i];
        }
        if (total < 0) return -1;
        
        // NOTE: at most one solution exists
        int cand = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += gas[i] - cost[i];
            if (cur < 0) {
                cand = i + 1;
                cur = 0;
            }
        }

        return cand;
    }
};
