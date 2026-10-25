class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        stack<int> s;
        for (int i = 0; i < t.size(); i++) {
            while (!s.empty() && t[i] > t[s.top()]) {
                int prev_index = s.top();
                s.pop();
                ans[prev_index] = i - prev_index;
            }
            s.push(i);
        }
        return ans;
    }
};