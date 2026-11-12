class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_count = 0;
        int dec_count = 0;
        int temp = 1;
        if (nums.size() == 1)
            return 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                temp++;
                dec_count = max(dec_count, temp);
            } else {
                temp = 1;
            }
        }
        temp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                temp++;
                inc_count = max(inc_count, temp);
            } else {
                temp = 1;
            }
        }
        if (inc_count == 0 && dec_count == 0)
            return 1;
        return max(inc_count, dec_count);
    }
};