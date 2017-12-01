class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        auto v = nums;
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            if (v[i] + v[i + 1] + v[i + 2] > 0) break;
            if (v[i] + v[n - 2] + v[n - 1] < 0) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = v[i] + v[l] + v[r];
                if (sum < 0) {
                    ++l;
                } else if (sum > 0) {
                    --r;
                } else {
                    res.push_back({ v[i], v[l], v[r] });
                    for (++l; l < r && v[l] == v[l - 1]; ++l) continue;
                    for (--r; l < r && v[r] == v[r + 1]; --r) continue;
                }
            }
        }
        return res;
    }
};
