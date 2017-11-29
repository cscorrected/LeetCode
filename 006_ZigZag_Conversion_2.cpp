class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) return s;
        string res;
        int period = 2 * (numRows - 1);
        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += period) {
                    res.push_back(s[j]);
                }
            } else {
                for (int j = i, k = period - i; j < s.size(); j += period, k += period) {
                    res.push_back(s[j]);
                    if (k < s.size()) res.push_back(s[k]);
                }
            }
        }
        return res;
    }
};