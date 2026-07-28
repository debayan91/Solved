class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        string a = bitset<16>(nums[0]).to_string(),
               b = bitset<16>(nums[1]).to_string(),
               c = bitset<16>(nums[2]).to_string();

        a = (nums[0] == 0) ? "0" : a.substr(a.find('1'));
        b = (nums[1] == 0) ? "0" : b.substr(b.find('1'));
        c = (nums[2] == 0) ? "0" : c.substr(c.find('1'));

        string a1 = a + b + c, a2 = a + c + b, a3 = b + a + c,
               a4 = b + c + a, a5 = c + a + b, a6 = c + b + a;

        int mx = 0;
        mx = max(mx, stoi(a1, nullptr, 2));
        mx = max(mx, stoi(a2, nullptr, 2));
        mx = max(mx, stoi(a3, nullptr, 2));
        mx = max(mx, stoi(a4, nullptr, 2));
        mx = max(mx, stoi(a5, nullptr, 2));
        mx = max(mx, stoi(a6, nullptr, 2));

        return mx;
    }
};