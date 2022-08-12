class Solution {
public:
    /*
     * Extremely simple 2D array question.
     */
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth = 0;
        
        for (int i = 0; i < accounts.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                temp += accounts[i][j];
            }
            
            if (temp > wealth) { wealth = temp; }
        }
        
        return wealth;
    }
};