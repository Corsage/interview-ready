class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0;
        
        sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        
        int def = properties[0][1];
        for (int i = 1; i < properties.size(); i++) {
            if (properties[i][1] < def) {
                count++;
            } else {
                def = properties[i][1];
            }
        }
        
        return count;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0;
        
        // Sort by 
        sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        vector<int> prev = properties[0];
        int index = 0;
        for (int i = 1; i < properties.size(); i++) {
            if (properties[i][0] > prev[0] && properties[i][1] > prev[1]) {
                count += i - index;
                prev = properties[i];
                index = i;
            }
            else if (i == properties.size() - 1) {
                prev = properties[++index];
                i = index;
            }
        }
        
        return count;
    }
};