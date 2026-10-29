class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_suffix(n);
        int maximum = INT_MIN;
        min_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            min_suffix[i] = min(nums[i], min_suffix[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            maximum = max(nums[i], maximum);
            if (maximum - min_suffix[i] <= k)
                return i;
        }
        return -1;
    }
};