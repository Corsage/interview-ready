class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int temp = 0;
        
        // Find all even val indexes.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                temp += nums[i];
            }
        }
        
        for (auto& query : queries) {
            int val = query[0];
            int index = query[1];
            
            // Handle our query updates.
            if (nums[index] % 2 == 0) {
                temp -= nums[index];
            }
            
            nums[index] += val;
            if (nums[index] % 2 == 0) {
                temp += nums[index];
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int temp = 0;
        unordered_set<int> uset;
        
        // Find all even val indexes.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                uset.insert(i);
                temp += nums[i];
            }
        }
        
        for (auto& query : queries) {
            int val = query[0];
            int index = query[1];
            
            // Handle our query updates.
            if (uset.find(index) != uset.end()) {
                temp -= nums[index];
                uset.erase(index);
            }
            
            nums[index] += val;
            if (nums[index] % 2 == 0) {
                temp += nums[index];
                uset.insert(index);
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};