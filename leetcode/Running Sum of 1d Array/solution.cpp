class Solution {
public:
    /*
     * Sometimes you gotta wake up and do an easy to get life going.
     */
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res[i] = sum;
        }
        
        return res;
    }
};