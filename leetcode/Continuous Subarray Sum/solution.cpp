class Solution {
public:
    
    bool checkSubarraySum(vector<int>& nums, int k) { 
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            int size = 1;
            
            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                size++;
                
                if (size >= 2 && sum % k == 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
};