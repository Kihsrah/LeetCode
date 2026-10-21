class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& c : tokens)
            if (c == "-" || c == "+" || c == "*" || c == "/") {
                if (c == "+") {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    int ans = left + right;
                    s.push(ans);
                } else if (c == "-") {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    int ans = left - right;
                    s.push(ans);
                } else if (c == "*") {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    int ans = left * right;
                    s.push(ans);
                } else {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    int ans = left / right;
                    s.push(ans);
                }
            } else {
                s.push(stoi(c));
            }
        return s.top();
    }
};