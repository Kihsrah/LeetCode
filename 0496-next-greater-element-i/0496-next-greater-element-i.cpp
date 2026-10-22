class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans;
        unordered_map<int, int> map;
        for (const int& x : nums2) {
            while (!s.empty() && x > s.top()) {
                map[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        for (const int& x : nums1) {
            if (map.find(x) != map.end()) {
                ans.push_back(map[x]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};