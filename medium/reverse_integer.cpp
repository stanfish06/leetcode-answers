#include<cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == -(pow(2, 31))) {
            return 0;
        }
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        int result = 0;        
        while(x > 0) {
            int next_digit = x % 10;
            if (result > ((pow(2, 31) - 1) - next_digit)/10) {
                result = 0;
                break;
            }
            result = 10 * result + next_digit;
            x /= 10;
        }
        return sign * result;
    }
};
