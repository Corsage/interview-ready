class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        
        // If vector changed size is an odd number,
        // it cannot have an original.
        if (changed.size() % 2 == 1) {
            return res;
        }
        
        // If it's an even size, it can possibly have
        // an original arr.
        int ogSize = changed.size() / 2;
        
        sort(changed.begin(), changed.end());
        queue<int> q;
        q.push(changed[0]);
        
        for (int i = 1; i < changed.size(); i++) {
            if (!q.empty()) {
                int temp = q.front() * 2;
                
                if (temp == changed[i]) {
                    res.push_back(q.front());
                    q.pop();
                } else {
                    q.push(changed[i]);
                }
            } else {
                q.push(changed[i]);
            }
        }
        
        if (q.empty()) {
            return res;
        }
        
        return vector<int> { };
    }
};