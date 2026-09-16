#define sz(a) (int)(a).size()

class Solution {
    string endWord;
    
public:
    bool hasEdge(string &a, string &b) {
        bool good = false;
        for (int i = 0; i < sz(a); ++i) {
            if (a[i] != b[i]) {
                if (good) return false;
                good = true;
            }
        }
        return good;
    }

    // q for the current side's BFS; dist2 for the other side's recorded distances; d for the current side's distance
    // How should I indicate that I'm done? Return -1 if not done, final answer otherwise
    int bfs(
        queue<string> &q,
        unordered_map<string, int> &dist1,
        int d,
        unordered_map<string, int> &dist2,
        vector<string> &wordList
    ) {
        int size = sz(q);
        for (int i = 0; i < size; ++i) {
            string word = q.front(); q.pop();
            if (dist2.count(word)) {
                return dist1[word] + dist2[word] + 1;
            }
            for (auto nei : wordList) {
                if (!dist1.count(nei) && hasEdge(word, nei)) {
                    dist1[nei] = d;
                    q.push(nei);
                }
            }
        }
        return -1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Bidirectional BFS intuition:
        // - simultaneously start a BFS from start and destination with 2 queues
        // - at each loop iteration, explore the smaller queue
        // - for each side, record the distance to every node in a map
        // - terminate the BFS when one side encounters a node that the other side has already seen; the distance to that node is current distance + previously recorded distance from the other side
        // optimization: rather than store words in the queues, store indexes from the wordList
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        this->endWord = endWord;
        queue<string> left, right;
        left.push(beginWord);
        right.push(endWord);
        unordered_map<string, int> distLeft, distRight;
        distLeft[beginWord] = distRight[endWord] = 0;
        int dLeft = 1, dRight = 1, res;
        while (!left.empty() && !right.empty()) {
            if (sz(left) <= sz(right)) {
                res = bfs(left, distLeft, dLeft, distRight, wordList);
                ++dLeft;
            } else {
                res = bfs(right, distRight, dRight, distLeft, wordList);
                ++dRight;
            }
            if (res != -1) {
                return res;
            }
        }
        return 0;
    }
};
