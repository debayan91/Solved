class Solution {
public:
    string con(int n){
        string res= ""; int k = 1 << 25;
        int z = n / k; res += string(z, 'z'); n = n % k;
        for(int i = 24; i >= 0; i--){
            if(n & (1LL << i)) res += char('a' + i);
        }
        return res;
    }
    vector<string> largestString(vector<int>& nums) {
        int n = size(nums); 
        vector<string> res;
        for(int a : nums) res.push_back(con(a));
        return res;
    }
};