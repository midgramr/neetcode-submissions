class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Idea: put every number into a sorted map, then just attempt to create groups of size groupSize, then slide a window across the key values. For each window start, check if you have at least 1 count of every key from windowStart until (not including) windowStart + groupSize; create a group and decrement each key count by 1; repeat until unsatisfiable or all groups created
        // { 1: 1, 2: 2, 3: 2, 4: 2, 5: 1 }, groupSize = 4

        map<int, int> mp;
        for (int e : hand) {
            mp[e]++;
        }

        // Actually, if my window start is k with count v, then I need to make sure a window ahead where each key has count >= k exists

        for (auto [k, v] : mp) {
            // If v = 0, then this element was already included in the middle of some other window
            if (v == 0) continue;
            for (int i = k; i < k + groupSize; ++i) {
                if (!mp.count(i) || mp[i] < v) {
                    return false;
                }
            }
            for (int i = k; i < k + groupSize; ++i) {
                mp[i] -= v;
            }
        }
        return true;
    }
};
