class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> res;
        auto v = nums;
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            if (v[i] + v[i + 1] + v[i + 2] + v[i + 3] > target) break;
            if (v[i] + v[n - 3] + v[n - 2] + v[n - 1] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && v[j] == v[j - 1]) continue;
                if (v[i] + v[j] + v[j + 1] + v[j + 2] > target) break;
                if (v[i] + v[j] + v[n - 2] + v[n - 1] < target) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum = v[i] + v[j] + v[l] + v[r];
                    if (sum < target) {
                        ++l;
                    } else if (sum > target) {
                        --r;
                    } else {
                        res.push_back({ v[i], v[j], v[l], v[r] });
                        for (++l; l < r && v[l] == v[l - 1]; ++l) continue;
                        for (--r; l < r && v[r] == v[r + 1]; --r) continue;
                    }
                }
            }
        }
        return res;
    }
};