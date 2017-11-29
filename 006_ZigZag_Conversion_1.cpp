class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) return s;
        vector<string> buf(numRows);
        int row = 0, step = 1;
        for (int i = 0; i < s.size(); ++i) {
            buf[row].push_back(s[i]);
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        s.clear();
        for (int j = 0; j < numRows; ++j) {
            s.append(buf[j]);
        }
        return s;
    }
};