// String Conversion:
class Solution {
   public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};

// Number Manipulation
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedNumber = 0;
        while (x > reversedNumber) {   // Reverse only the last half of x
            reversedNumber *= 10;      // Shift all digits to the left by 1
            reversedNumber += x % 10;  // Add the last digit of x
            x /= 10;                   // Remove last digit of x
        }

        return x == reversedNumber || x == reversedNumber / 10;  // Throw away the middle number
    }
};