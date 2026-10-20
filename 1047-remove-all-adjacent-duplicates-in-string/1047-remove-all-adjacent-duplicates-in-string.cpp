class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ss;
        string ans = "";
        int i = 1;
        ss.push('K');
        ss.push(s[0]);
        while (i < s.size()) {
            if (ss.empty())
                return "";
            char top = ss.top();
            if (top == s[i]) {
                ss.pop();
            } else {
                ss.push(s[i]);
            }
            i++;
        }

        while (!ss.empty()) {
            ans += ss.top();
            ss.pop();
        }

        reverse(ans.begin(), ans.end());
        ans.erase(0, 1);
        return ans;
    }
};