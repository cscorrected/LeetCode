class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        auto v = nums;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            int j = i + 1, k = v.size() - 1;
            while (j < k) {
                int sum = v[i] + v[j] + v[k];
                if (sum < 0) {
                    ++j;
                } else if (sum > 0) {
                    --k;
                } else {
                    res.push_back({ v[i], v[j], v[k] });
                    for (++j; j < k && v[j] == v[j - 1]; ++j) continue;
                    for (--k; j < k && v[k] == v[k + 1]; --k) continue;
                }
            }
        }
        return res;
    }
};