class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int max_count = 0;
        while (i < nums.size()) {
            int count = 0;
            if (nums[i] == 1) {
                while(i < nums.size() && nums[i] == 1) {
                    count++;
                    i++;
                }
                max_count = max(max_count, count);
            }
            i++;
        }
        return max_count;
    }
};