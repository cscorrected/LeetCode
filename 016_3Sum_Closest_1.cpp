class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return INT_MAX;
        if (nums.size() == 3) return accumulate(nums.begin(), nums.end(), 0);
        int minSum = INT_MAX, minDiff = INT_MAX;
        auto v = nums;
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = v[i] + v[l] + v[r];
                if (sum == target) return sum;
                int diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    minSum = sum;
                }
                if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return minSum;
    }
};