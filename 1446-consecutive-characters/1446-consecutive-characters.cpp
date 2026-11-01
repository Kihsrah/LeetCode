class Solution {
public:
    int maxPower(string s) {
        int i = 1;
        int count = 0;
        if (s.size() == 1) {
            return 1;
        }
        while (i < s.size()) {
            int temp = 1;
            while (i < s.size() && s[i] == s[i - 1]) {
                temp++;
                i++;
            }
            count = max(temp , count);
            i++;
        }
        return count;
    }
};