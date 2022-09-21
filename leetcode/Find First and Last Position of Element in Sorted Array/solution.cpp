class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res { -1, -1 };
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            int num = nums[mid];
            
            // Check if mid has our target.
            if (num == target) {
                // Find where it started.
                int i = mid;
                int j = mid;
                
                while (i >= 0 && nums[i] == target) {
                    i--;
                }
                
                while (j < nums.size() && nums[j] == target) {
                    j++;
                }
                
                res[0] = i + 1;
                res[1] = j - 1;
                break;
                
            } else if (num > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return res;
    }
};