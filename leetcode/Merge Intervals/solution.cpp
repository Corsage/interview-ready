class Solution {
public:
    /**
     * By sorting the input intervals, we only need to check
     * the current interval with the prev one to see if a
     * merge is required.
     * 
     * Time complexity - O(n log n) and Space complexity - O(1).
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            int s1 = res[res.size() - 1][0];
            int e1 = res[res.size() - 1][1];
            
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            
            if (e1 >= s2) {
                res[res.size() - 1][1] = max(e1, e2);
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};