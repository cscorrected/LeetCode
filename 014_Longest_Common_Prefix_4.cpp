class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            int temp = strs[i].size();
            n = min(n, temp);
        }
        int low = 1, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommon(strs, low, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }
    bool isCommon(vector<string>& strs, int low, int mid) {
        for (int i = low - 1; i < mid; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) return false;
            }
        }
        return true;
    }
};