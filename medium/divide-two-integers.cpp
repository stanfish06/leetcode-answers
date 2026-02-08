#include <iostream>
#include <climits>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int result = 0;
        int result_signed = 0;
        if (dividend == 0) {
            return 0;
        }
        bool is_nonneg = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        unsigned int a = 0;
        unsigned int b = 1;
        if (dividend == -INT_MAX-1) {
            a = INT_MAX;
            a++;
        } else {
            a = dividend > 0 ? dividend : (-dividend);
        }
        if (divisor == -INT_MAX-1) {
            b = INT_MAX;
            b++;
        } else {
            b = divisor > 0 ? divisor : (-divisor);
        }
        if (b == 1) {
            result = a;
        } else {
            unsigned int incre = b;
            unsigned int incre_result = 1;
            for (unsigned int i = b; i <= a; i = i + incre) {
                result+=incre_result;
                if (incre < UINT_MAX - b) {
                    incre = incre << 1; // this grows exponentially and odd cases are covered by b
                    incre_result = incre_result << 1;
                }
                if (i + incre > a || i > (UINT_MAX - incre)) {
                    incre = b;
                    incre_result = 1;
                }
                if (i + incre > a || i > (UINT_MAX - incre)) {
                    break;
                }
            }
        }
        if (!is_nonneg) {
            if (result > UINT_MAX) {
                return -INT_MAX-1;
            }
            result_signed = -result;    
        } else {
            if (result > INT_MAX) {
                return INT_MAX;
            } else {
                result_signed = result;    
            }
        }
        return result_signed;
    }
};

int main() {
    Solution sol;
    std::cout << sol.divide(-2147483648, 1) << std::endl;
}
