class Solution {
public:
    string intToRoman(int num) {
        const vector<int> vals = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        const vector<string> strs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string res;
        for (int i = 0; i < vals.size(); ++i) {
            int n = num / vals[i];
            for (int j = 0; j < n; ++j) {
                res.append(strs[i]);
            }
            num %= vals[i];
        }
        return res;
    }
};