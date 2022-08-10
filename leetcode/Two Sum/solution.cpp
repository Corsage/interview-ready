class Solution {
public:
    /*
     * Initial Logic:
     * Use a map to store the number and its associated index.
     * Perform target - nums[i] to find the other number.
     * If it exists in the map, return the pair.
     *
     * Time complexity - O(n) and Space complexity - O(1).
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        
        unordered_map<int, int> map;
        map.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            auto item = map.find(temp);
            
            if (item != map.end())
            {
                result[0] = item->second;
                result[1] = i;
                break;
            }
            
            map.insert({nums[i], i});
        }
        
        return result;
    }
};