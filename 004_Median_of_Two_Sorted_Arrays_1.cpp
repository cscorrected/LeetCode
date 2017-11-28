class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool cond = nums1.size() < nums2.size();
        int m = (cond ? nums1.size() : nums2.size());
        int n = (cond ? nums2.size() : nums1.size());
        auto& A = (cond ? nums1 : nums2);
        auto& B = (cond ? nums2 : nums1);
        int iMin = 0, iMax = m;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2, j = (m + n) / 2 - i;
            if (i > 0 && A[i - 1] > B[j]) {
                iMax = i - 1;
            } else if (i < m && A[i] < B[j - 1]) {
                iMin = i + 1;
            } else {
                int rightMin = (i == m ? B[j] : (j == n ? A[i] : min(A[i], B[j])));
                if ((m + n) % 2) return rightMin;
                int leftMax = (i == 0 ? B[j - 1] : (j == 0 ? A[i - 1] : max(A[i - 1], B[j - 1])));
                return (rightMin + leftMax) / 2.0;
            }
        }
        return 0.0;
    }
};