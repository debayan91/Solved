class Solution {
public:
    void add(vector<char>& v, int pos, int val) {
        while (val > 0) {
            int current = (v[pos] - '0') + val;
            v[pos] = '0' + (current % 10);
            val = current / 10;
            pos++;
        }
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size();
        int m = num2.size();

        vector<char> v(n + m, '0');

        for (int i = 0; i < m; i++) {
            int b = num2[i] - '0';

            int carry = 0;

            for (int j = 0; j < n; j++) {
                int a = num1[j] - '0';

                int current = a * b + carry;

                int digit = current % 10;
                carry = current / 10;

                add(v, i + j, digit);
            }

            if (carry > 0) {
                add(v, i + n, carry);
            }
        }

        while (v.size() > 1 && v.back() == '0') {
            v.pop_back();
        }

        string ans(v.begin(), v.end());
        reverse(ans.begin(), ans.end());

        return ans;
    }
};