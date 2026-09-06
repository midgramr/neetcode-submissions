class Solution {
public:
    vector<int> getKey(string &s) {
        vector<int> key(26);
        for (auto &c : s) {
            key[c - 'a']++;
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groups;
        for (auto s : strs) {
            groups[getKey(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &[_, group] : groups) {
            ans.push_back(group);
        }
        return ans;
    }
};
