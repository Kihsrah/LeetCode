class Solution {
public:
    int myAtoi(string s) {
        int i = 0, negative = 0;
        long long result = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        while (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                negative = 1;
            }
            i++;
            break;
        }

        while (i < s.size() && isdigit(s[i])) {
            int temp = s[i] - '0';

            if (result > (INT_MAX - temp) / 10) {
                return negative == 0 ? INT_MAX : INT_MIN;
            } else {
                result = result * 10 + temp;
            }
            i++;
        }

        if (negative == 1) {
            return 0 - result;
        }
        return result;
    }
};