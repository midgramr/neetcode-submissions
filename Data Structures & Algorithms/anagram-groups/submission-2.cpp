class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Use sorted characters as hashtable key, values are the anagrams
        unordered_map<string, vector<string>> anagrams;
        for (auto &s : strs) {
            string key{s};
            sort(key.begin(), key.end());
            anagrams[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &[_, a] : anagrams) {
            ans.push_back(a);
        }
        return ans;
    }
};
