class Solution {
public:
    /*
     * Very extreme naive solution.
     * Get all the distances into an array and then sort it.
     */
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> distances;
        
        // Sliding window.
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int temp = abs(nums[i] - nums[j]);
                distances.push_back(temp);
            }
        }
            
        sort(distances.begin(), distances.end());
        return distances[k - 1];
    }
};