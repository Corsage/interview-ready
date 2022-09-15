class Solution {
public:
    /*
     * https://en.wikipedia.org/wiki/Digital_root
     * Uses the direct formula to calculate the digital root
     * of num.
     */
    int addDigits(int num) {
        if (num == 0) { return 0; }
        else if (num % 9 == 0) {
            return 9;
        } else {
            return num % 9;
        }
    }

    int sum(int num) {
        int res = 0;
        
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        
        return res;
    }
    
    int addDigits(int num) {
        
        while (sum(num) >= 10) {
            num = sum(num);
        }
        
        return sum(num);
    }
};