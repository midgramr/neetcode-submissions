class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Cannot simply take the largest number from each slot, since merging 2 triplets could cause one slot to overshoot the target
        // Obviously, the numbers in each slot of target must appear in the correct slot somewhere in triplets
        // Ideally, if we are trying to build slot A, we're looking for a triplet in triplets that looks like [A, b, c], where b and c are <= the target B and C. Actually, we want b and c to be as small as possible since that gives us the largest number of candidates to merge with to build B and C

        // Idea: split the triplets into 3 groups, one group for each slot of target. Within each group, sort by something? I could either sort by slot 2 or slot 3, but I'm not sure which one to prioritize

        // The final target will be formed by matching at most 3 triplets, so I'm looking for the 3

        // Actually, do I even need to minimize b and c? Can I just find any triplets where b and c are less than the target values? So basically, at any point in time, if I can just set the target value for one of the slots and have the other two slots still available for merging later, then I should just select that triplet
        int a = -1, b = -1, c = -1;
        int x = target[0], y = target[1], z = target[2];
        for (auto triplet : triplets) {
            auto i = triplet[0], j = triplet[1], k = triplet[2];
            if (i <= x && j <= y && k <= z) {
                a = max(a, i);
                b = max(b, j);
                c = max(c, k);
            }
        }
        return a == x && b == y && c == z;
    }
};
