#define sz(a) (int)(a).size()

class Solution {
public:
    bool hasEdge(string &a, string &b) {
        // Letter must differ in exactly one position
        bool good = false;
        for (int i = 0; i < sz(a); ++i) {
            if (a[i] != b[i]) {
                if (good) return false;
                good = true;
            }
        }
        return good;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Just run BFS
        queue<string> q;
        unordered_set<string> seen;
        seen.insert(beginWord);
        q.push(beginWord);
        int d = 1;
        while (!q.empty()) {
            int size = sz(q);
            for (int i = 0; i < size; ++i) {
                auto word = q.front(); q.pop();
                if (word == endWord) {
                    return d;
                }
                for (auto next : wordList) {
                    if (!seen.count(next) && hasEdge(word, next)) {
                        seen.insert(next);
                        q.push(next);
                    }
                }
            }
            ++d;
        }
        return 0;
    }
};
