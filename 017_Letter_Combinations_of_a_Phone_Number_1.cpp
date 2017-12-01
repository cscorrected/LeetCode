class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> dict = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        if (digits.empty() || digits.find('0') != string::npos || digits.find('1') != string::npos) return {};
        vector<string> res = { "" };
        for (const auto& digit : digits) {
            vector<string> temp;
            for (const auto& s : res) {
                for (const auto& c : dict[digit - '0']) {
                    temp.push_back(s + c);
                }
            }
            res.swap(temp);
        }
        return std::move(res);
    }
};