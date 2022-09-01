class Solution {
public:
    
    /*
     * We notice a pattern when checking test cases.
     * 1 = 1
     * 2 = 2
     * 3 = 3
     * 4 = 5
     * 5 = 8
     * 6 = 13
     * 7 = 21
     * 8 = 34
     *
     * This is the Fibonacci sequence, so we just code that.
     * 
     * Time complexity: O(n) and Space complexity - O(1).
     */
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }
        
        // Similar to fibonacci sequence.
        int x = 2;
        int y = 3;
        
        for (int i = 4; i <= n; i++) {
            int temp = x + y;
            x = y;
            y = temp;
        }
        
        return y;
    }

    void rClimbStairs(int& n, int temp, int& ways) {
        if (temp == n) {
            ways++;
            return;
        } else if (temp > n) {
            return;
        }
        
        rClimbStairs(n, temp + 1, ways);
        rClimbStairs(n, temp + 2, ways);
    }
    
    int climbStairs(int n) {
        int ways = 0;
        rClimbStairs(n, 0, ways);
        
        return ways;
    }
};