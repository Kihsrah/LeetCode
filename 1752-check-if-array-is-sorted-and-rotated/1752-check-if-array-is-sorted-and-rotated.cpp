class Solution {
public:
    bool check(vector<int>& nums) {
        int i;
        if (nums.size() <= 2)
            return true;
        for (i = 0; i < nums.size() - 1 && nums[i] <= nums[i + 1]; i++) {
        }
        i++;
        if (i < nums.size() && nums.back() > nums[0]) {
            return false;
        }
        for (int j = i; j < nums.size() - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                return false;
            }
        }
        return true;
    }
};