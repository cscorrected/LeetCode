class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() || digits.find('0') != string::npos || digits.find('1') != string::npos) return {};
        vector<string> res;
        helper(digits, 0, "", res);
        return res;
    }
    void helper(string& digits, int offset, string prefix, vector<string>& res) {
        if (offset >= digits.size()) {
            res.push_back(prefix);
            return;
        }
        static const vector<string> dict = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        auto& letters = dict[digits[offset] - '0'];
        for (int i = 0; i < letters.size(); ++i) {
            helper(digits, offset + 1, prefix + letters[i], res);
        }
    }
};