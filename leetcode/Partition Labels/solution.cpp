class Solution {
public:

    vector<int> partitionLabels(string s) {
        vector<int> res;
        int alpha[26];
        
        // Keep updating where the char was last seen.
        for (int i = 0; i < s.size(); i++) {
            alpha[s[i] - 'a'] = i;
        }
        
        int prev = -1;
        int next = 0;
        
        for (int i = 0; i < s.size(); i++) {
            next = max(next, alpha[s[i] - 'a']);
            
            if (next == i) {
                // Reached the end of a partition.
                res.push_back(next - prev);
                prev = next;
            }
        }
        
        return res;
    }

    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> m;
        
        // Keep updating where the char was last seen.
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        
        int prev = -1;
        int next = 0;
        
        for (int i = 0; i < s.size(); i++) {
            next = max(next, m[s[i]]);
            
            if (next == i) {
                // Reached the end of a partition.
                res.push_back(next - prev);
                prev = next;
            }
        }
        
        return res;
    }

    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> m;
        vector<pair<int, int>> ranges;
        vector<int> res;
        
        for (int i = 0; i < s.size(); i++) {
            // Character doesn't exist, add it.
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = make_pair(i, i);
            } else {
                // Update where the new range ends.
                m[s[i]] = make_pair(m[s[i]].first, i);
            }
        }
        
        // Put values into vector so we can sort the ranges.
        for (auto it = m.begin(); it != m.end(); ++it ) {
            ranges.push_back(it->second);
        }
        
        sort(ranges.begin(), ranges.end());
    
        int start = ranges[0].first;
        int end = ranges[0].second;
        
        for (auto& pair : ranges) {
            // We reach a new partition.
            if (pair.first > end) {
                res.push_back(end - start + 1);
                start = pair.first;
                end = pair.second;
            } else if (pair.first < end && pair.second < end) {
                // This is part of our answer.
            } else if (pair.first < end && pair.second > end) {
                end = pair.second;
            }
            
            // cout << pair.first << " , " << pair.second << endl; 
        }
        
        // Add the last one.
        res.push_back(end - start + 1);
        
        
        
        return res;
    }
};