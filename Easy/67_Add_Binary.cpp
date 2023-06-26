class Solution {
   public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.size() - 1, j = b.size() - 1;

        string ans;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            ans += to_string(sum % 2);
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
   public:
    string addBinary(string a, string b) {
        int carry = 0, diff = a.size() - b.size();
        if (diff < 0) {
            for (int i = 0; i < -diff; i++) {
                a.insert(a.begin(), '0');
            }
        } else if (diff > 0) {
            for (int i = 0; i < diff; i++) {
                b.insert(b.begin(), '0');
            }
        }

        string ans;
        for (int i = a.size() - 1; i >= 0; i--) {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            if (sum >= 2) {
                carry = 1;
                ans += to_string(sum % 2);
            } else {
                ans += to_string(sum);
                if (carry) carry = 0;
            }
        }
        if (carry) ans += to_string(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};