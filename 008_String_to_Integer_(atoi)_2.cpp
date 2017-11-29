class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i = 0;
        while (i < str.size() && isspace(str[i])) {
            ++i;
        }
        if (i == str.size()) return 0;
        int sign = (str[i] == '-' ? -1 : 1);
        if (str[i] == '-' || str[i] == '+') ++i;
        int res = 0;
        while (i < str.size() && isdigit(str[i])) {
            int temp = res * 10 + sign * (str[i] - '0');
            if (temp / 10 != res) return (sign == 1 ? INT_MAX : INT_MIN);
            res = temp;
            ++i;
        }
        return res;
    }
};