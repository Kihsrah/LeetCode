class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;

        for (char c : s) {
            if (c == '(') {
                ss.push(')');
            } else if (c == '{') {
                ss.push('}');
            } else if (c == '[') {
                ss.push(']');
            } else {
                if (ss.empty() || c != ss.top()) {
                    return false;
                }
                ss.pop();
            }
        }
        return ss.empty();
    }
};