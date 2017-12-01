class Solution {
public:
    bool isValid(string s) {
        stack<char> buf;
        for (const auto c : s) {
            if (c == '(') {
                buf.push(')');
            } else if (c == '[') {
                buf.push(']');
            } else if (c == '{') {
                buf.push('}');
            } else if (!buf.empty() && c == buf.top()) {
                buf.pop();
            } else {
                return false;
            }
        }
        return buf.empty();
    }
};