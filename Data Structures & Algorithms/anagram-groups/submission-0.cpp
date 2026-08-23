class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (auto it : strs) {
            vector<int> count(26, 0);
            for (auto c : it) {
                count[c - 'a']++;
            }
            string key;

            for (int freq : count) {
                key += to_string(freq) + ",";
            }
            mpp[key].push_back(it);
        }
        vector<vector<string>> res;
        for (auto [key, val] : mpp) {
            res.push_back(val);
        }
        return res;
    }
};
