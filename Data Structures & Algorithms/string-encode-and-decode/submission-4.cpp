#define sz(a) (int)(a).size()

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (auto &s: strs) {
            encoded += to_string(sz(s));
            encoded += '#';
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < sz(s)) {
            int len = 0;
            int j;
            for (j = i; j < sz(s) && s[j] != '#'; ++j) {
                len = 10 * len + (s[j] - '0');
            }
            i = j + 1;
            ans.push_back(s.substr(i, len));
            i += len;
        }
        return ans;
    }
};
