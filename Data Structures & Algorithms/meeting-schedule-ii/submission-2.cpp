#define sz(a) (int)(a).size()

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // When a conflict is encountered, a new room must be created -> minimize the number of conflicts
        // Idea: select a maximal set of intervals with no conflicts; there may be intervals remaining, so repeat that until there are no more intervals
        // This should be doable in a single pass by maintaining a data structure of all the latest room times and creating a new room whenever all of the existing times overlap with the next time
        
        // The room times can be tracked with a sorted datastruture, since we want to pick the latest available room that can accomodate the new time
        // For example:
        // rooms: [1, 3, 5]
        // next intervals: [3, 6], [2, 6]
        // Here, we want to put [3, 6] after the room with 3 and the [2, 6] after the room with 1, since that leaves us with the most options later

        if (intervals.empty()) return 0;

        map<int, int> rooms;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            if (a.end != b.end) return a.end < b.end;
            return a.start < b.start;
        });

        rooms[intervals[0].end] = 1;
        for (int i = 1; i < sz(intervals); ++i) {
            auto in = intervals[i];
            // Want to find the latest time available that can accomodate the new interval
            // it is the first room where end > in.start
            auto it = rooms.upper_bound(in.start);
            if (it == rooms.begin()) {
                rooms[in.end]++;
            } else {
                --it;
                it->second--;
                if (it->second == 0) rooms.erase(it);
                rooms[in.end]++;
            }
        }

        int total = 0;
        for (auto [k, v] : rooms) total += v;
        return total;
    }
};
