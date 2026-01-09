// Palindrome number
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            int quo = x;
            int rem = 0;
            unsigned long long x_rev = 0;
            while (quo > 0) {
                rem = quo % 10;
                quo = quo / 10;
                x_rev = x_rev * 10 + rem;
            }
            return x == x_rev;
        }
    }
};
