class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int original = x;
        long long y = 0;

        while (x > 0) {
            int last = x % 10;
            y = y * 10 + last;
            x = x / 10;
        }

        return original == y;
    }
};