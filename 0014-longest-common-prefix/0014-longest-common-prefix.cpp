class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        string longest = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            string temp = strs[i];
            while (j < temp.size() && temp[j] == longest[j]) {
                ans.push_back(longest[j]);
                j++;
            }
            longest.resize(j);
            if (longest == "") return "";
        }
        return longest;
    }
};