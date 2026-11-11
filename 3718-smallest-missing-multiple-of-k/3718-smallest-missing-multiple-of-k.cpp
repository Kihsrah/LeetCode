class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int next_sum = k;
        for (int i = 0; i < nums.size(); i++) {
           if (nums[i] % k == 0  && nums[i] == next_sum) {
            next_sum += k;
            continue;
           }
           else if (nums[i] % k == 0 && nums[i] > next_sum) {
            return next_sum;
           }
        }
        return next_sum;
    }
};