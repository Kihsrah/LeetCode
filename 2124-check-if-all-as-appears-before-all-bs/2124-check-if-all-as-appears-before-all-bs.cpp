class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        for (i = 0; i < s.size() && s[i] != 'b'; i++) {
        }
        while (i < s.size()) {
            if (s[i] == 'a') {
                return false;
            }
            i++;
        }
        return true;
    }
};