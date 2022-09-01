class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        
        // Sort the array first.
        sort(nums.begin(), nums.end());
        
        // To maximize min we take an ascending array
        // and pair min(i, i + 1) = i always.
        // Using sliding window method.
        for (int i = 0; i < nums.size() - 1; i += 2) {
            sum += nums[i];
        }
            
        return sum;
    }
};