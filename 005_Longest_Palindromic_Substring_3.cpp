class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        vector<int> T = { -3, -2 };
        for (int i = 0; i < s.size(); ++i) {
            T.push_back(s[i]);
            T.push_back(-2);
        }
        T.push_back(-1);
        int n = T.size();
        vector<int> P(n);
        int c = 0, r = 0;
        for (int i = 1; i < n - 1; ++i) {
            P[i] = (i < r ? min(r - i, P[2 * c - i]) : 0);
            while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
                ++P[i];
            }
            if (i + P[i] > r) {
                r = i + P[i];
                c = i;
            }
        }
        int center, lmax = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > lmax) {
                lmax = P[i];
                center = i;
            }
        }
        return s.substr((center - lmax - 1) / 2, lmax);
    }
};