class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sums;
        
        if (nums.size() < 3) {
            return false;
        }
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int temp = nums[i] + nums[i + 1];
            
            if (!sums.insert(temp).second) {
                return true;
            }
        }
        
        return false;
    }
};