class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i = 0;
        while (i < str.size() && isspace(str[i])) {
            ++i;
        }
        if (i == str.size()) return 0;
        long long sign = (str[i] == '-' ? -1 : 1);
        if (str[i] == '-' || str[i] == '+') ++i;
        long long base = 0, res = 0;
        while (i < str.size() && isdigit(str[i])) {
            base = base * 10 + (str[i] - '0');
            res = sign * base;
            if (res > INT_MAX) return INT_MAX;
            if (res < INT_MIN) return INT_MIN;
            ++i;
        }
        return res;
    }
};