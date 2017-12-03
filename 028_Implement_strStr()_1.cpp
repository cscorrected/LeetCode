class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; ; ++i) {
            for (int j = 0; ; ++j) {
                int k = i + j;
                if (j == needle.size()) return i;
                if (k == haystack.size()) return -1;
                if (needle[j] != haystack[k]) break;
            }
        }
    }
};