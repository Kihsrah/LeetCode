class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        for (i = 1; i < s.size(); i++) {
            if (s[i - 1] > s[i]) {
                return false;
            }
        }
        return true;
    }
};