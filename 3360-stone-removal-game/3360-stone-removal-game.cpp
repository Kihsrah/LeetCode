class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;
        int toSubtract = 10;
        while (n >= 0) {
            count++;
            n -= toSubtract;
            toSubtract--;
            if (count % 2 == 0 && n < 0) {
                return true;
            } else if (count % 2 != 0 && n < 0) {
                return false;
            }
        }
        return false;
    }
};