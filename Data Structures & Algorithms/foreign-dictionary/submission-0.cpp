#define sz(a) (int)(a).size()

struct TrieNode {
    vector<TrieNode*> children;
    bool word;
    TrieNode() : word(false), children(26) {}
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
};

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // Validity checks:
        // 1. If a < b, then a must appear before b in every position where it matters
        // 2. If a is a prefix of b, then a must appear before b in the word list
        // Idea: construct a graph where a -> b if letter a comes before b in words; attempt to find a topological ordering then check the prefix condition after

        // Intuitively feels like a trie would help here: 
        // iterate through the list of words and gradually construct the trie as I go
        // for each word while traversing the trie, I can start to establish edges in my graph

        // Two implementation details:
        // 1. Graph construction: detailed above
        // 2. Efficient prefix checks: construct a trie by iterating backwards; if at any point I encounter a word in which a prefix is a final word, then the prefix condition is unsatisfied

        TrieNode root;

        // One slot for each lowercase letter in the alphabet
        vector<int> indeg(26);
        vector<unordered_set<int>> adj(26);
        unordered_set<char> chrs;

        // Graph construction
        for (auto &word : words) {
            TrieNode *cur = &root;
            for (auto chr : word) {
                // Here, check whether the current letter comes after any existing letters under the same prefix
                chrs.insert(chr);
                int c = chr - 'a';
                for (int i = 0; i < 26; ++i) {
                    if (i != c && cur->children[i]) {
                        // Here, want to avoid pushing duplicate edges
                        if (!adj[i].count(c)) {
                            adj[i].insert(c);
                            indeg[c]++;
                        }
                    }
                }
                if (!cur->children[c]) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->word = true;
            // Here, I can actually check to see if any existing word already starts with this word is a prefix
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i]) return "";
            }
        }

        // Run top-sort
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (chrs.count(i + 'a') && indeg[i] == 0) {
                q.push(i);
            }
        }

        string order;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            order += (char)(c + 'a');
            for (auto nei : adj[c]) {
                indeg[nei]--;
                if (indeg[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        cout << order << endl;
        if (sz(order) == sz(chrs)) {
            return order;
        }
        return "";
    }
};
