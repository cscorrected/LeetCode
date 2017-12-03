class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (const auto& word : words) {
            ++counts[word];
        }
        int n = s.size(), num = words.size(), len = words[0].size();
        vector<int> res;
        for (int i = 0; i < n - num * len + 1; ++i) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; ++j) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) == counts.end()) break;
                ++seen[word];
                if (seen[word] > counts[word]) break;
            }
            if (j == num) res.push_back(i);
        }
        return res;
    }
};