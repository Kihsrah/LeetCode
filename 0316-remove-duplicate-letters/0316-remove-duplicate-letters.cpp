class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> map;
        unordered_map<char, bool> visited;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]--;

            if (visited[s[i]] == true)
                continue;

            while (!ans.empty() && ans.back() > s[i] && map[ans.back()] > 0) {
                visited[ans.back()] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visited[s[i]] = true;
        }
        return ans;
    }
};