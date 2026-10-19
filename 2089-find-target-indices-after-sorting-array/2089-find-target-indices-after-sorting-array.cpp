class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                count++;
            }
            if (nums[i] == target) {
                count2++;
            }
        }
        while (count2 > 0) {
            ans.push_back(count);
            count++;
            count2--;
        }
        return ans;
    }
};