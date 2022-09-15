class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int h1 = -1001;
        int h2 = -1002;
        int h3 = -1003;
        
        int l1 = 1001;
        int l2 = 1002;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > h1) {
                h3 = h2;
                h2 = h1;
                h1 = nums[i];
            } else if (nums[i] > h2) {
                h3 = h2;
                h2 = nums[i];
            } else if (nums[i] > h3) {
                h3 = nums[i];
            }
            
            if (nums[i] < l1) {
                l2 = l1;
                l1 = nums[i];
            } else if (nums[i] < l2) {
                l2 = nums[i];
            }
        }
        
        int a = h1 * h2 * h3;
        int b = l1 * l2 * h1;
        
        return (a > b) ? a : b;
    }

    int maximumProduct(vector<int>& nums) {
        vector<int> asc(nums);
        vector<int> desc(nums);
        
        sort(asc.begin(), asc.end());
        sort(desc.begin(), desc.end(), [](int a, int b) {
           return a > b; 
        });
        
        int a = desc[0] * desc[1] * desc[2];
        int b = asc[0] * asc[1] * desc[0];
        
        return (a > b) ? a : b;
    }
};